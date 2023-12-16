// bellman ford, check for cycles
//need to fing longest path instead of shortest path,
// so use -ve of weights provided

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e17;
const int ninf= -1e17; //negative infinity
struct edge{
    int src;
    int dest;
    int weight;
};

int32_t main()
{
    int n,m;
    cin>>n>>m;

    vector<edge> v;
    for(int i=0;i<m;i++)
    {
        edge a;
        cin>>a.src>>a.dest>>a.weight;
        a.weight = a.weight *-1; //inverse of bellman ford
        v.push_back(a);
    }

    vector<int> dist(n+1,inf);
    dist[1]=0;

    for(int i=0;i<n;i++)
    {
        for(auto e: v)
        {
            int u= e.src, v=e.dest, w=e.weight;
            if(dist[u]==inf) {continue;}

            dist[v] = min(dist[v], dist[u]+w);
            dist[v] = max(dist[v], ninf);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(auto e: v)
        {
            int u= e.src, v=e.dest, w=e.weight;
            if(dist[u]==inf) {continue;}

            dist[v] = max(dist[v], ninf);
            if(dist[v] > dist[u]+w)
            {
                dist[v] = ninf;
            }
        }
    }

    if(dist[n]==inf || dist[n]==ninf)
    {
        cout<<"-1\n";
    }
    else{
        cout<<-1*dist[n]<<endl;
    }
}