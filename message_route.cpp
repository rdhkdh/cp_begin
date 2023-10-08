#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> parent(n+1,0);
    vector<int> dist(n+1,INT_MAX);
    vector<int> adj[n+1]; //array of vectors

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    dist[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int x= q.front();
        q.pop();
        for(int u: adj[x])
        {
            if(dist[u]==INT_MAX)
            {
                parent[u]=x;
                dist[u]= dist[x]+1;
                q.push(u);
            }
        }
    }

    if(dist[n]==INT_MAX) {cout<<"IMPOSSIBLE\n";}
    else
    {
        cout<<dist[n]+1<<endl;
        vector<int> path;
        path.push_back(n);
        
        while(path.back()!=1)
        {
            path.push_back( parent[path.back()] );
        }
        reverse(path.begin(),path.end());
        for(auto u: path) {cout<<u<<" ";}
    }

    return 0;
}