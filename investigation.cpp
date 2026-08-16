/*
Because edge weights are strictly positive ($c \ge 1$), the shortest path graph 
forms a DAG (Directed Acyclic Graph). Just like we did dynamic programming on a 
DAG in Game Routes, Dijkstra processes vertices in increasing order of shortest 
distance from the source. This means Dijkstra's relaxation step gives us the 
topological ordering we need for DP on the shortest paths DAG.
*/

#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MOD = 1e9+7;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1); // a: (b1,c1), (b2,c2)...
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    //perform djikstra's and DP
    vector<long long> dist(n+1, INF); //dist[i] = min dist from 1->i
    vector<int> count_routes(n+1, 0); //count_routes[i] = no of min dist routes from 1->i
    vector<int> min_flights(n+1, 1e9); //min_flights[i] = min no of flights on a min dist route from 1->i
    vector<int> max_flights(n+1, -1); //max_flights[i] = max no of flights on a min dist route from 1->i

    //min heap with pairs: (dist, second node)
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    dist[1] = 0;
    count_routes[1] = 1;
    min_flights[1] = 0;
    max_flights[1] = 0;

    pq.push({0,1});

    while(!pq.empty())
    {
        auto [d,u] = pq.top();
        pq.pop();
        
        if((long long)(d) > dist[u]) {continue;}

        for(auto edge: adj[u])
        {
            int v = edge.first;
            int w = edge.second;

            if(dist[u]+w < dist[v]) 
            {
                dist[v] = dist[u] + (long long)(w); //relax the edge
                count_routes[v] = count_routes[u];
                min_flights[v] = min_flights[u] + 1;
                max_flights[v] = max_flights[u] + 1;
                pq.push({dist[v], v});
            }
            else if(dist[u]+w == dist[v]) //node was revisited
            {
                count_routes[v] = (count_routes[v] + count_routes[u]) % MOD;
                min_flights[v] = min(min_flights[v], min_flights[u]+1);
                max_flights[v] = max(max_flights[v], max_flights[u]+1);
            }
        }
    }

    cout<<dist[n]<<" "<<count_routes[n]<<" "<<min_flights[n]<<" "<<max_flights[n]<<endl;
}