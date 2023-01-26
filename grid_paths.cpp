#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> arr(1010);

bool isValid(int x, int y)
{
    if (x < 0)
    {
        return false;
    }
    if (y < 0)
    {
        return false;
    }
    if (arr[x][y] == '*')
    {
        return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char a;
            cin >> a;
            arr[i].push_back(a);
        }
    }

    vector<vector<int>> dp(n, vector<int>(n,0));

    if(arr[0][0]=='.') { dp[0][0] = 1; }

    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j <n; j++)
        {
            if(arr[i][j]=='.')
            {    
                if (isValid(i - 1, j))
                {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] = dp[i][j]%1000000007;
                }

                if (isValid(i, j - 1))
                {
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] = dp[i][j]%1000000007;
                }
            }
            
        }
    }

    cout<<dp[n-1][n-1];
}
