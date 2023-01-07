#include <bits/stdc++.h>
using namespace std;
int visited[1010][1010];
int neighbourC[4] = {1, -1, 0, 0};
int neighbourR[4] = {0, 0, 1, -1};
int n, m;
char mat[1010][1010];

bool isValid(int r, int c)
{
    if (c < 0)
    {
        return false;
    }
    if (r < 0)
    {
        return false;
    }
    if (c >= m)
    {
        return false;
    }
    if (r >= n)
    {
        return false;
    }
    if (mat[r][c] == '#')
    {
        return false;
    }
    return true;
}

void dfs(int r, int c)
{
    visited[r][c] = 1;
    for (int i = 0; i < 4; i++)
    {
        int c1 = c + neighbourC[i];
        int r1 = r + neighbourR[i];
        if (isValid(r1, c1))
        {
            if (!visited[r1][c1])
                dfs(r1, c1);
        }
    }
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            visited[i][j] = 0;
        }
    }
    
    int count=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '.' && !visited[i][j])
            {
                dfs(i, j);
                count++;
            }
        }
    }
    cout << count;
}