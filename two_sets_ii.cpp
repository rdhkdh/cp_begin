#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int MOD = 1e9+7;
    int n;
    cin>>n;

    int sum = (n*(n+1))/2;
    int s = sum/2;
    vector<vector<int>> dp(n,vector<int>(s+1,0));

    if(sum%2==1) {cout<<0<<endl; return 0;}
    else{
        dp[0][0] = 1;
        for (int i = 1; i < n; i++) 
        {
            for (int j = 0; j <= s; j++) 
            {
                dp[i][j] = dp[i-1][j];
                int left = j-i;
                if (left >= 0) 
                {
                    (dp[i][j] += dp[i-1][left]) %= MOD;
                }
            }
        }
    }

    cout<<dp[n-1][s]<<endl;

    return 0;
}