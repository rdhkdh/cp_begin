#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n,x;
    cin>>n>>x;
    int c[n];
    for(int i=0;i<n;i++) {cin>>c[i];}

    vector<vector<int>> dp(n+1, vector<int> (x+1,0)); //initializing (n+1)*(x+1) matrix of 0s
    dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            dp[i][j]=dp[i-1][j];
            int rem=j-c[i-1];
            if(rem>=0) 
            { 
                dp[i][j] += dp[i][rem]; 
                dp[i][j] = dp[i][j]%1000000007;
            } // c[i-1] for access purpose, not (i-1)th coin !            
        }
    }
    
    cout<<dp[n][x];
}