#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int s[n],t[m];
    for(int i=0;i<n;i++) {cin>>s[i]; s[i]=s[i]%1000;}
    for(int i=0;i<m;i++) {cin>>t[i];}
    sort(t,t+m);

    int count=0;
    for(int i=0;i<n;i++)
    {
        if( binary_search(t,t+m,s[i]) ) {count++;} 
    }
    cout<<count<<endl;
}