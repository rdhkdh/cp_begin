#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
vector<int> visited(100005,0);

void dfs(int v)
{
    if(visited[v]) {return;}
    visited[v]=1;
    for(auto u: adj[v]) {dfs(u);}
}

int main()
{
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=m;i++) { cin>>a>>b; adj[a].push_back(b); adj[b].push_back(a); }

    vector<int> res;
    for(int i=1; i<=n; i++) 
    {
        if(!visited[i]) {res.push_back(i); dfs(i);}
    }

    cout<<res.size()-1<<endl;
    for(int i=0;i<res.size()-1;i++) 
    {
        cout<<res[i]<<" "<<res[i+1]<<endl;
    }
}