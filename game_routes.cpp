#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
vector<vector<int>> adj;
vector<int> color;
vector<int> dag; //topological sort

void dfs(int v)
{
    if(color[v]==1 || color[v]==2) {return;} //acyclic given in ques

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    adj.resize(n+1);
    color.resize(n+1, 0);

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    //obtain topological sort
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0) {dfs(i);}
    }
    reverse(dag.begin(), dag.end()); 

    //dp[i] = no of ways of going from 1->i
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    for(auto u: dag)
    {
        for(auto t: adj[u])
        {
            dp[t] = (dp[t] + dp[u]) % mod; //child += parent's no of ways
        }
    }

    cout<<dp[n]<<endl;
}