#include<bits/stdc++.h>
using namespace std;

int treeCut(int n, int k, vector<vector<int>> edges)
{
    //fill adjacency graph
    vector<vector<int>> adj(n+1);
    for(auto e: edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    //write bfs function - counts number of nodes from src within radius r
    auto count = [&](int src, int r) {
        vector<int> dist(n+1,-1);
        queue<int> q;
        dist[src]=0;
        q.push(src);
        int cnt=0; //count of nodes within r from src

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto v: adj[u])
            {
                cnt++;
                if(dist[v]==-1 && dist[u]+1 <= r) //not visited and within r
                {
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
        }

        return cnt;
    };


    //binary search on diameter value
    int lo = 0, hi = n-1;
    while(lo<hi)
    {
        int mid = (lo+hi)/2;
        int d = mid;
        bool flag = false;

        for(int i=1; i<=n; i++)
        {
            int x = count(i, d/2);

            if(x>=n-k)
            {
                flag = true;
                break;
            }
        }

        if(flag==true) {hi = mid;}
        else{lo = mid+1;}
    }

    return lo;
}


int main()
{
    int n,k,r,c;
    vector<vector<int>> edges;

    cin>>n;
    cin>>k;
    cin>>r;
    cin>>c;

    int x1, x2;
    for(int i=1; i<=r; i++)
    {
        cin>>x1>>x2;
        vector<int> v;
        v.push_back(x1);
        v.push_back(x2);
        edges.push_back(v);
    }

    int ans = treeCut(n, k, edges);
    cout<<ans<<endl;
}

