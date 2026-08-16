#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;
vector<int> dag;

void dfs(int v)
{
    if(color[v]==2 || color[v]==1) {return;}

    color[v] = 1;
    for(auto u: adj[v])
    {
        dfs(u);
    }
    color[v] = 2;
    dag.push_back(v);
}

int main()
{
    int n,m;
    cin>>n>>m;

    adj.resize(n+1);

    int a,b;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b); //dag
    }

    color.resize(n+1, 0);
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0) {dfs(i);}
    }
    reverse(dag.begin(), dag.end()); //topological order

    //use DP, and iterate through nodes in topological order
    //dist[i] = max no of cities from 1 -> i
    vector<int> dist(n+1, INT_MIN);
    vector<int> parent(n+1);
    dist[1] = 1;
    parent[1] = 1; //source node
    for(auto u: dag)
    {
        if(dist[u]==INT_MIN) {continue;}
        for(auto v: adj[u])
        {
            if(dist[v] < dist[u]+1)
            {
                dist[v] = dist[u]+1;
                parent[v] = u;
            }
        }
    }


    if(dist[n]==INT_MIN) {cout<<"IMPOSSIBLE"<<endl;}
    else{
        cout<<dist[n]<<endl;

        vector<int> ans;
        int x = n;
        while(parent[x] != x)
        {
            ans.push_back(x);
            x = parent[x];
        }
        ans.push_back(x);
        reverse(ans.begin(), ans.end());

        for(auto u: ans)
        {
            cout<<u<<" ";
        }
        cout<<endl;
    }
}