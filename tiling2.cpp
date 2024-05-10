#include <bits/stdc++.h>
using namespace std;

bool backtrack(int idx, int H, int W, vector<pair<int, int>> &remaining_tiles, vector<vector<char>> &grid)
{
    if (idx == H * W)
    {
        return true;
    }

    int row = idx / W;
    int col = idx % W;

    if (grid[row][col] != '.')
    {
        return backtrack(idx + 1, H, W, remaining_tiles, grid);
    }

    for (int i = 0; i < remaining_tiles.size(); ++i)
    {
        int a = remaining_tiles[i].first;
        int b = remaining_tiles[i].second;

        for (int j = 0; j < 2; ++j)
        { // Try both orientations
            if (a <= H - row && b <= W - col)
            {
                bool can_place = true;
                for (int r = row; r < row + a; ++r)
                {
                    for (int c = col; c < col + b; ++c)
                    {
                        if (grid[r][c] != '.')
                        {
                            can_place = false;
                            break;
                        }
                    }
                    if (!can_place)
                    {
                        break;
                    }
                }
                if (can_place)
                {
                    vector<vector<char>> new_grid = grid;
                    for (int r = row; r < row + a; ++r)
                    {
                        for (int c = col; c < col + b; ++c)
                        {
                            new_grid[r][c] = i + '1';
                        }
                    }
                    remaining_tiles.erase(remaining_tiles.begin() + i);
                    if (backtrack(idx + 1, H, W, remaining_tiles, new_grid))
                    {
                        return true;
                    }
                }
            }
            swap(a, b); // Rotate the tile
        }
    }
    return false;
}

bool can_cover_grid(int H, int W, int N, vector<pair<int, int>> &tiles)
{
    int total_area = H * W;
    int total_tile_area = 0;
    for (const auto &tile : tiles)
    {
        total_tile_area += tile.first * tile.second;
    }

    if (total_tile_area < total_area)
    {
        return false;
    }

    vector<vector<char>> grid(H, vector<char>(W, '.'));

    return backtrack(0, H, W, tiles, grid);
}

int main()
{
    int N, H, W;
    cin >> N >> H >> W;
    vector<pair<int, int>> tiles;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        tiles.push_back(make_pair(a, b));
    }

    cout << (can_cover_grid(H, W, N, tiles) ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}
