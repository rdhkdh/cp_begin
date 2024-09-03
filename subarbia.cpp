#include<bits/stdc++.h>
using namespace std;

int bfs(int v, vector<bool> visited, vector<vector<int>> adj)
{
    int n = visited.size();
    vector<int> dist(n);
    
    visited[v] = true;
    dist[v]=0;
    queue<int> q;
    q.push(v);

    while(!q.empty())
    {
        int t = q.front();
        q.pop();

        for(auto u: adj[t])
        {
            if(!visited[u])
            {
                visited[u] = true;
                dist[u] = dist[t]+1;
                q.push(u);
            }
        }
    }

    int sum=0;
    for(auto x: dist)
    {
        sum += x;
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> adj(n);

    int u,v;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    for(int i=0;i<n;i++)
    {
        vector<bool> visited(n,false);
        cout<<bfs(i, visited, adj)<<endl;
    }



}