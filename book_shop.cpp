#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    
    int h[n+1],s[n+1];
    for(int i=1;i<=n;i++) {cin>>h[i];}
    for(int i=1;i<=n;i++) {cin>>s[i];}
    
    int dp[n+1][x+1]; //max no of pages by selecting from 1,2...ith books, using j money
    for(int i=0;i<=x;i++) { dp[0][i]= 0; }
    for(int i=1;i<=n;i++) { dp[i][0]= 0; }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(j-h[i]>=0)
            {
                dp[i][j]= max( dp[i-1][j], dp[i-1][j-h[i]]+s[i] );
            }
            else{ dp[i][j]= dp[i-1][j]; }
        }
    }

    cout<<dp[n][x]<<endl;
}