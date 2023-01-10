#include<bits/stdc++.h>
using namespace std;
vector<int> visited(100,0);
vector<vector<int>> adj(100);

void dfs(int v)
{
    visited[v]=1;
    cout<<v<<" ";
    for(auto u: adj[v])
    {
        if(!visited[u]) {dfs(u);}
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    
    dfs(1);
}