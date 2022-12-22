#include<bits/stdc++.h>
using namespace std;
#define MAXN 200010

vector<vector<int>> adj(MAXN);

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

    
}