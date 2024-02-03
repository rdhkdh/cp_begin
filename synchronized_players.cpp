#include<bits/stdc++.h>
using namespace std;

#define N 70
char grid[N][N];

// QItem for current location and distance
// from source location
class QItem {
public:
    int row;
    int col;
    int dist;
    QItem(int x, int y, int w)
        : row(x), col(y), dist(w)
    {
    }
};
 
int minDistance(char grid[N][N], int n)
{
    QItem source(0, 0, 0);
    int count=0;
 
    // To keep track of visited QItems. Marking
    // blocked cells as visited.
    bool visited[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '#')
                visited[i][j] = true;
            else
                visited[i][j] = false;
 
            // Finding source
            if (grid[i][j] == 'P' && count==0)
            {
                count++;
                source.row = i;
                source.col = j;
            }
        }
    }
 
    // applying BFS on matrix cells starting from source
    queue<QItem> q;
    q.push(source);
    visited[source.row][source.col] = true;
    while (!q.empty()) {
        QItem p = q.front();
        q.pop();
 
        // Destination found;
        if (grid[p.row][p.col] == 'P' && count==1)
            return p.dist;
 
        // moving up
        if (p.row - 1 >= 0 &&
            visited[p.row - 1][p.col] == false) {
            q.push(QItem(p.row - 1, p.col, p.dist + 1));
            visited[p.row - 1][p.col] = true;
        }
 
        // moving down
        if (p.row + 1 < n &&
            visited[p.row + 1][p.col] == false) {
            q.push(QItem(p.row + 1, p.col, p.dist + 1));
            visited[p.row + 1][p.col] = true;
        }
 
        // moving left
        if (p.col - 1 >= 0 &&
            visited[p.row][p.col - 1] == false) {
            q.push(QItem(p.row, p.col - 1, p.dist + 1));
            visited[p.row][p.col - 1] = true;
        }
 
         // moving right
        if (p.col + 1 < n &&
            visited[p.row][p.col + 1] == false) {
            q.push(QItem(p.row, p.col + 1, p.dist + 1));
            visited[p.row][p.col + 1] = true;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;

    string str;

    for(int i=0;i<n;i++)
    {
        cin>>str;
        for(int j=0;j<n;j++)
        {
            grid[i][j] = str[j];
        }
    }

    cout << minDistance(grid, n);
}