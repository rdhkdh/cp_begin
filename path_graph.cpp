#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(m!=n-1) {cout<<"No\n"; return 0;}
    //else
    //{
        vector<int> adj[n+1];
        for(int i=0;i<m;i++) 
        {
            int u,v; 
            cin>>u>>v;
            if(u!=v)
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        int count1=0,flag=0;
        for(int i=1;i<=n;i++)
        {
            int s=adj[i].size();
            if(s>2) {flag=1; break;}
            if(s==0) {flag=1; break;}
            if(s==1) {count1++;}
            flag=0;
        }
        if(count1!=2) {flag=1;}
        (flag==1)? cout<<"No\n" : cout<<"Yes\n";
    //}
}