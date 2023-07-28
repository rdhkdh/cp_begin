#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int x[n];
    int max_sum=0;
    for(int i=0;i<n;i++) 
    {
        cin>>x[i]; 
        max_sum+=x[i];
    }

    vector<vector<bool>> dp(n+1,vector<bool>(max_sum+1,false));
    dp[0][0]=true;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=max_sum;j++)
        {
            dp[i][j]= dp[i-1][j]; //not choosing ith coin
            if(j-x[i-1]>=0 && dp[i-1][j-x[i-1]]) //choosing ith coin
            {
                dp[i][j]=true;
            }
        }
    }

    vector<int> possible;
    for (int j = 1; j <= max_sum; j++) 
    {
        if (dp[n][j]) { possible.push_back(j); }
    }
    
    cout << possible.size() << endl;
    for (int v : possible) {cout << v << ' ';}
    cout << endl;

    return 0;
}