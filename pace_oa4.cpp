#include<bits/stdc++.h>
using namespace std;

int maxPathSum(vector<vector<int>> board, int p, int q)
{
    int n = board.size();
    int m = board[0].size();

    int dp[n][m];
    for(int j=0;j<m;j++)
    {
        dp[n-1][j] = board[n-1][j];
    }

    for(int i=n-2; i>=0; i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(j==0)
            {
                dp[i][j] = board[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
            }
            else if(j==m-1)
            {
                dp[i][j] = board[i][j] + max(dp[i+1][j-1], dp[i+1][j]);
            }
            else
            {
                dp[i][j] = board[i][j] + max(dp[i+1][j-1], max(dp[i+1][j], dp[i+1][j+1]));
            }
        }
    }

    int dpr[n][m]; //reverse
    for(int j=0;j<m;j++)
    {
        dpr[0][j] = board[0][j];
    }

    for(int i=1; i<=n-1; i++)
    {
        for(int j=m-1; j>=0; j--)
        {
            if(j==0)
            {
                dpr[i][j] = board[i][j] + max(dpr[i-1][j], dpr[i-1][j+1]);
            }
            else if(j==m-1)
            {
                dpr[i][j] = board[i][j] + max(dpr[i-1][j-1], dpr[i-1][j]);
            }
            else
            {
                dpr[i][j] = board[i][j] + max(dpr[i-1][j-1], max(dpr[i-1][j], dpr[i-1][j+1]));
            }
        }
    }

    return max(dp[0][p], dpr[n-1][q]);
}

int main()
{
    int n,m;
    cin>>n;
    cin>>m;

    vector<vector<int>> board(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
        }
    }

    int p,q;
    cin>>p;
    cin>>q;

    cout<<maxPathSum(board, p, q)<<endl;
}