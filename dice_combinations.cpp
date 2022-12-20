#include<bits/stdc++.h>
using namespace std;
#define int long long int 

int32_t main()
{
    int n;
    cin>>n;

    vector<int> dp(n+1,0); //intializing a vector of size n+1, filled with zeros
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=6 && i-j>=0;j++)
        {
            dp[i] = dp[i]+dp[i-j];
            
        } 
        dp[i]=dp[i]%1000000007;
    }

    cout<<dp[n];
}