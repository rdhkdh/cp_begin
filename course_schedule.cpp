#include<bits/stdc++.h>
using namespace std;

vector<int> color;
vector<vector<int>> adj;
vector<int> topl_sort_rev;

bool dfs(int v)
{
    if(color[v]==2) {return false;} //black
    if(color[v]==1) {return true;} //grey, cycle detected

    bool res = false; //assume acyclic by default

    color[v] = 1; //grey
    for(auto u: adj[v])
    {
        res = res || dfs(u);
    }
    color[v] = 2; //black
    topl_sort_rev.push_back(v);

    return res;
}

int main()
{
    int n,m;
    cin>>n>>m;

    adj.resize(n+1);
    color.resize(n+1, 0); //white

    int a,b;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b); // a is prereq of b
    }

    bool isCyclic = false; //assume acyclic
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            isCyclic = isCyclic || dfs(i);
        }
    }

    if(isCyclic) {cout<<"IMPOSSIBLE"<<endl;}
    else{
        reverse(topl_sort_rev.begin(), topl_sort_rev.end());
        for(auto u: topl_sort_rev)
        {
            cout<<u<<" ";
        }
        cout<<endl;
    }
}