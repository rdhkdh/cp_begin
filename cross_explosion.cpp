#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W, Q;
    cin >> H >> W >> Q;

    map<int, set<int>> row_walls;
    map<int, set<int>> col_walls;

    for (int i = 0; i < H; i++)
    {
        set<int> s;
        row_walls[i] = s;
        for (int j = 0; j < W; j++)
        {
            row_walls[i].insert(j);
        }
    }

    for (int j = 0; j < W; j++)
    {
        set<int> s;
        col_walls[j] = s;
        for (int i = 0; i < H; i++)
        {
            col_walls[j].insert(i);
        }
    }

    int R, C, destroyed_count = 0;
    while (Q--)
    {
        cin >> R >> C;
        R = R - 1;
        C = C - 1;

        if (row_walls[R].find(C) != row_walls[R].end())
        {
            // Destroy the wall at (R, C)
            row_walls[R].erase(C);
            col_walls[C].erase(R);
            destroyed_count++;
        }
        else
        {
            // Wall at (R, C) is already destroyed, search for other walls
            // Up
            auto it_up = col_walls[C].lower_bound(R);
            if (it_up != col_walls[C].begin())
            {
                --it_up; //finding the largest value smaller than given integer
                row_walls[*it_up].erase(C);
                col_walls[C].erase(it_up);
                destroyed_count++;
            }

            // Down
            auto it_down = col_walls[C].upper_bound(R);
            if (it_down != col_walls[C].end())
            {
                row_walls[*it_down].erase(C);
                col_walls[C].erase(it_down);
                destroyed_count++;
            }

            // Left
            auto it_left = row_walls[R].lower_bound(C);
            if (it_left != row_walls[R].begin())
            {
                --it_left; //finding the largest value smaller than given integer
                col_walls[*it_left].erase(R);
                row_walls[R].erase(it_left);
                destroyed_count++;
            }

            // Right
            auto it_right = row_walls[R].upper_bound(C);
            if (it_right != row_walls[R].end())
            {
                col_walls[*it_right].erase(R);
                row_walls[R].erase(it_right);
                destroyed_count++;
            }
        }
    }

    cout<<H*W - destroyed_count<<endl;
}