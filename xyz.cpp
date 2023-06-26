#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    int k;
    cin>>n>>k;
    int a[n+1];
    int c[n+1] = {0}; //c[0]=0
    map<int,int> mp;
    int count=0;
    mp[c[0]]=1;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        c[i] = c[i-1]+a[i];
        mp[c[i]]++;
    }

    
    for(int j=1;j<=n;j++)
    {
        if(binary_search(c,c+j,c[j]-k)) {count+=mp[c[j]-k];}
    }
    if(k==0) {count=count/2;}
    cout<<count<<endl;
}