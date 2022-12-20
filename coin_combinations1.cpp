#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n,x;
    cin>>n>>x;
    int c[n];
    for(int i=0;i<n;i++) {cin>>c[i];}

    vector<int> dp(x+1,0);
    for(int i=0;i<n;i++) 
    {
        if(c[i]<=x) { dp[c[i]]=1; }
    }
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-c[j]>=0) { dp[i]= dp[i]+dp[i-c[j]]; }
        }
        dp[i]= dp[i]%1000000007;
    }

    cout<<dp[x];
}