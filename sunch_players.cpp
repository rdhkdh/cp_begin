#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cell {
    int x, y;
    Cell(int _x, int _y) : x(_x), y(_y) {}
};

int minMoves(vector<string>& grid) {
    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, -1));
    vector<pair<int, int>> players;

    // Find player positions and initialize BFS queue
    queue<Cell> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'P') {
                players.emplace_back(i, j);
                dist[i][j] = 0;
                q.push(Cell(i, j));
            }
        }
    }

    // Check if players are already in the same cell
    if (players.size() != 2) return -1;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = curr.x + dx[d];
            int ny = curr.y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[curr.x][curr.y] + 1;
                q.push(Cell(nx, ny));
            }
        }
    }

    return dist[players[0].first][players[0].second] == -1 ? -1 : dist[players[0].first][players[0].second];
}

int main() {
    int n;
    cout << "Enter the size of the grid: ";
    cin >> n;

    vector<string> grid(n);
    cout << "Enter the grid (each row as a separate string):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int moves = minMoves(grid);
    cout << "Minimum number of moves required: " << moves << endl;

    return 0;
}
