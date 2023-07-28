#include<bits/stdc++.h>
using namespace std;

int main()
{
    string A,B;
    cin>>A>>B;

    int a= A.length();
    int b= B.length();

    int dp[a+1][b+1];
    for(int j=0;j<=b;j++)
    {
        dp[0][j]= j;
    }
    for(int i=1;i<=a;i++)
    {
        dp[i][0]=i;
    }
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(A[i-1]==B[j-1]) { dp[i][j]= dp[i-1][j-1]; }
            else
            {
                dp[i][j]= min( min( dp[i][j-1]+1, dp[i-1][j]+1 ), dp[i-1][j-1]+1 );
            }
        }
    }

    cout<<dp[a][b]<<endl;

    return 0;
}