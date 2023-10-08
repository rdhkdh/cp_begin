#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
bool bad;
int visited[MAX], group[MAX]; //which group they're in
vector<int> adj[MAX];

void dfs(int x = 1, bool g = 0) 
{
	visited[x] = 1;
	group[x] = g;
	for (int u : adj[x])
    {
        //if group of immediate ancestor of u is same as u, then graph is not bipartite
        if (visited[u]) { if(group[u]==g) bad=true; } 
        else { dfs(u, !g); }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;!bad && i<=n;i++)
    {
        if(!visited[i]) {dfs(i);}
    }
    
    if(bad) {cout<<"IMPOSSIBLE\n";}
    else{
        for(int i=1;i<=n;i++)
        {
            cout<<group[i]+1<<" ";
        }
    }

    return 0;
}