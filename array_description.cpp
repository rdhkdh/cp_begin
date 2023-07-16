#include<bits/stdc++.h>
using namespace std;
int main()
{
    int mod = 1e9+7;
    int n,m;
    cin>>n>>m;
    int x[n];
    for(int i=0;i<n;i++) {cin>>x[i];}

    vector<vector<int>> dp(n,vector<int>(m+1,0));
    if(x[0]==0)
    {
        fill(dp[0].begin(),dp[0].end(),1);
    }
    else{ dp[0][x[0]]=1; }

    for(int i=1; i<n; i++)
    {
        if(x[i]==0)
        {
            for(int j=1;j<=m;j++)
            {
                for(int k: {j-1,j,j+1})
                {
                    if(k>=1 && k<=m) { (dp[i][j] += dp[i-1][k])%= mod; }
                }
            }
        }
        else
        {   
            for( int k: {x[i]-1,x[i],x[i]+1} )
            {
                if(k>=1 && k<=m) { (dp[i][x[i]] += dp[i-1][k]) %= mod; }
            }
        }
    }

    int ans=0;
    for(int j=1;j<=m;j++) { (ans+= dp[n-1][j]) %= mod; }
    cout<<ans<<endl;
}