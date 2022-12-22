#include<bits/stdc++.h>
using namespace std;
#define MAXN 202020

vector< vector<int> > adj(MAXN);
vector<int> subtree_size(MAXN);

int calc(int node) // calculates (subtree size of node)+1
{
    if(adj[node].size()==0) {return 1;} // its a leaf
    else{
        for(int i=0;i<adj[node].size();i++)
        subtree_size[node] += calc( adj[node][i] ) ;
    }
    return subtree_size[node]+1;
}

int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x; // x is boss of i
        adj[x].push_back(i);
    }

    calc(1);

    for(int i=1;i<=n;i++) {cout<<subtree_size[i]<<" ";}
}