#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin>>n;
    int x[n], sum=0;
    for(int i=0;i<n;i++) 
    {
        cin>>x[i];
        sum += x[i];
    }

    int dp[n][n];   

    for(int l=n-1;l>=0;l--)
    {
        for(int r=l; r<n;r++)
        {
            if(l==r) {dp[l][r]= x[l];}
            else{
                dp[l][r] = max(x[l]-dp[l+1][r], x[r]-dp[l][r-1]);
            }
        }
    }

    int ans = (dp[0][n-1] + sum)/2;
    cout<<ans<<endl;

    return 0;
}