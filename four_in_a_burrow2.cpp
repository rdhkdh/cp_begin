#include<bits/stdc++.h>
using namespace std;

bool check_cell(int x, int y)
{
    if(x<0 || x>=6 || y<0 || y>=7) {return false;}
    return true;
}

bool check_diagonals(int x, int y, vector<vector<char>> grid)
{
    bool flag1= true;
    for(int i=1;i<=3;i++)
    {
        if(check_cell(x+i, y+i) && grid[x+i][y+i]==grid[x][y])
        {
            continue;
        }
        else
        {
            flag1= false;
            break;
        }
    }

    bool flag2= true;
    for(int i=1;i<=3;i++)
    {
        if(check_cell(x+i, y-i) && grid[x+i][y-i]==grid[x][y])
        {
            continue;
        }
        else
        {
            flag2= false;
            break;
        }
    }

    return (flag1 || flag2);
}

bool check_horizontals(int x, int y, vector<vector<char>> grid)
{
    bool flag1= true;
    for(int i=1;i<=3;i++)
    {
        if(check_cell(x, y+i) && grid[x][y+i]==grid[x][y])
        {
            continue;
        }
        else
        {
            flag1= false;
            break;
        }
    }

    bool flag2= true;
    for(int i=1;i<=3;i++)
    {
        if(check_cell(x, y-i) && grid[x][y-i]==grid[x][y])
        {
            continue;
        }
        else
        {
            flag2= false;
            break;
        }
    }

    return (flag1 || flag2);
}

bool check_verticals(int x, int y, vector<vector<char>> grid)
{
    bool flag1= true;
    for(int i=1;i<=3;i++)
    {
        if(check_cell(x+i, y) && grid[x+i][y]==grid[x][y])
        {
            continue;
        }
        else
        {
            flag1= false;
            break;
        }
    }

    bool flag2= true;
    for(int i=1;i<=3;i++)
    {
        if(check_cell(x-i, y) && grid[x-i][y]==grid[x][y])
        {
            continue;
        }
        else
        {
            flag2= false;
            break;
        }
    }

    return (flag1 || flag2);
}

int main()
{
    freopen("four_in_a_burrow_validation_input.txt", "r", stdin);
    freopen("four_in_a_burrow_validation_output.txt", "w", stdout);

    int t;
    cin>>t;
    int og=t;

    while(t--)
    {
        vector<vector<char>> grid(6, vector<char>(7)); // 6x7 grid

        for(int i=0;i<6;i++)
        {
            for(int j=0;j<7;j++)
            {
                cin>>grid[i][j];
            }
        }

        char winner = '0';
        for(int i=5;i>=0;i--)
        {
            for(int j=0;j<7;j++)
            {
                if(check_horizontals(i,j,grid) || check_verticals(i,j,grid) || check_diagonals(i,j,grid))
                {
                    if(winner=='0') 
                    {
                        winner = grid[i][j];
                    }
                    else if(winner!=grid[i][j])
                    {
                        winner='?'; 
                        break;
                    }
                }
            }
            if(winner!='0') {break;}
        }

        cout<<"Case #"<<og-t<<": "<<winner<<endl;
    }
}