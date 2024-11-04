#include <bits/stdc++.h>
using namespace std;

char check_winner(vector<vector<char>> &grid)
{
    int rows = 6, cols = 7;

    vector<vector<pair<int, int>>> f_diagonals;
    vector<vector<pair<int, int>>> f_horizontals;
    vector<vector<pair<int, int>>> f_verticals;

    vector<vector<pair<int, int>>> c_diagonals;
    vector<vector<pair<int, int>>> c_horizontals;
    vector<vector<pair<int, int>>> c_verticals;

    // Check horizontal lines
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = 0; j <= cols - 4; j++)
        {
            if (grid[i][j] == 'C' && grid[i][j + 1] == 'C' && grid[i][j + 2] == 'C' && grid[i][j + 3] == 'C')
            {
                vector<pair<int, int>> v = {make_pair(i, j), make_pair(i, j + 1), make_pair(i, j + 2), make_pair(i, j + 3)};
                c_horizontals.push_back(v);
            }
            if (grid[i][j] == 'F' && grid[i][j + 1] == 'F' && grid[i][j + 2] == 'F' && grid[i][j + 3] == 'F')
            {
                vector<pair<int, int>> v = {make_pair(i, j), make_pair(i, j + 1), make_pair(i, j + 2), make_pair(i, j + 3)};
                f_horizontals.push_back(v);
            }
        }
    }

    // Check vertical lines
    for (int j = 0; j < cols; j++)
    {
        for (int i = rows - 4; i >= 0; i--)
        {
            if (grid[i][j] == 'C' && grid[i + 1][j] == 'C' && grid[i + 2][j] == 'C' && grid[i + 3][j] == 'C')
            {
                vector<pair<int, int>> v = {make_pair(i, j), make_pair(i + 1, j), make_pair(i + 2, j), make_pair(i + 3, j)};
                c_verticals.push_back(v);
            }
            if (grid[i][j] == 'F' && grid[i + 1][j] == 'F' && grid[i + 2][j] == 'F' && grid[i + 3][j] == 'F')
            {
                vector<pair<int, int>> v = {make_pair(i, j), make_pair(i + 1, j), make_pair(i + 2, j), make_pair(i + 3, j)};
                f_verticals.push_back(v);
            }
        }
    }

    // Check top-left to bottom-right diagonals (\ direction)
    for (int sum = 0; sum <= rows + cols - 2; sum++)
    {
        for (int i = 0; i < rows; i++)
        {
            int j = sum - i; 
            if (j >= 0 && j < cols && i + 3 < rows && j + 3 < cols)
            {
                if (grid[i][j] == 'C' && grid[i + 1][j + 1] == 'C' && grid[i + 2][j + 2] == 'C' && grid[i + 3][j + 3] == 'C')
                {
                    vector<pair<int, int>> v = {make_pair(i, j), make_pair(i + 1, j+1), make_pair(i + 2, j+2), make_pair(i + 3, j+3)};
                    c_diagonals.push_back(v);
                }
                if (grid[i][j] == 'F' && grid[i + 1][j + 1] == 'F' && grid[i + 2][j + 2] == 'F' && grid[i + 3][j + 3] == 'F')
                {
                    vector<pair<int, int>> v = {make_pair(i, j), make_pair(i + 1, j+1), make_pair(i + 2, j+2), make_pair(i + 3, j+3)};
                    f_diagonals.push_back(v);
                }
            }
        }
    }

    // Check bottom-left to top-right diagonals (/ direction)
    for (int diff = -(rows - 1); diff <= cols - 1; diff++)
    {
        for (int i = 0; i < rows; i++)
        {
            int j = i - diff; 
            if (j >= 0 && j < cols && i + 3 < rows && j - 3 >= 0)
            {
                if (grid[i][j] == 'C' && grid[i + 1][j - 1] == 'C' && grid[i + 2][j - 2] == 'C' && grid[i + 3][j - 3] == 'C')
                {
                    vector<pair<int, int>> v = {make_pair(i, j), make_pair(i + 1, j-1), make_pair(i + 2, j-2), make_pair(i + 3, j-3)};
                    c_diagonals.push_back(v);
                }
                if (grid[i][j] == 'F' && grid[i + 1][j - 1] == 'F' && grid[i + 2][j - 2] == 'F' && grid[i + 3][j - 3] == 'F')
                {
                    vector<pair<int, int>> v = {make_pair(i, j), make_pair(i + 1, j-1), make_pair(i + 2, j-2), make_pair(i + 3, j-3)};
                    f_diagonals.push_back(v);
                }
            }
        }
    }

    if(
        f_diagonals.size()==0 &&
        f_horizontals.size()==0 &&
        f_verticals.size()==0 &&
        c_diagonals.size()==0 &&
        c_horizontals.size()==0 &&
        c_verticals.size()==0
    )
    {
        return '0';
    }
    
    if(
        f_diagonals.size()==0 &&
        f_horizontals.size()==0 &&
        f_verticals.size()==0
    )
    {
        return 'C';
    }

    if(
        c_diagonals.size()==0 &&
        c_horizontals.size()==0 &&
        c_verticals.size()==0
    )
    {
        return 'F';
    }

    //both are non zero
    
    
}

int main()
{
    // Example grid (6x7)
    vector<vector<char>> grid = {
        {'C', 'C', 'F', 'F', 'F', 'C', 'F'},
        {'C', 'F', 'F', 'C', 'C', 'F', 'C'},
        {'C', 'C', 'F', 'F', 'C', 'F', 'F'},
        {'F', 'F', 'C', 'C', 'F', 'C', 'F'},
        {'C', 'F', 'F', 'C', 'C', 'C', 'F'},
        {'F', 'C', 'F', 'F', 'F', 'C', 'C'}};

    // Check the winner
    string winner = check_winner(grid);
    cout << "Winner: " << winner << endl;

    return 0;
}
