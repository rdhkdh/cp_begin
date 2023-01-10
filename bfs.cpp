#include<bits/stdc++.h>
using namespace std;
vector<int> visited(100,0);
queue<int> q;
vector<vector<int>> adj(100);

void bfs(int x)
{
    visited[x]=1;
    q.push(x);
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        cout<<s<<" ";
        for(auto u: adj[s])
        {
            if(!visited[u])
            {
                visited[u]=1;
                q.push(u);
            }
        }
    }
}

int main()
{
    int n; //no. of nodes
    cin>>n;
    for(int i=1;i<=n-1;i++) //n-1 edges
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    bfs(1);
}