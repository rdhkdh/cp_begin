#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    vector<string> grid;

    while(getline(cin, str))
    {
        grid.push_back(str);
    }

    int m = grid.size();
    int n = grid[0].size();

    vector<pair<int,int>> dirn = {
        {0,1}, {0,-1}, {1,0}, {-1,0},
        {1,1}, {1,-1}, {-1,1}, {-1,-1}
    };

    
    vector<string> temp_grid = grid;
    int res=0;

    while(true)
    {
        int ans=0; //no of paper rolls to remove
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='.') {continue;}

                int count=0;

                //check all 8 adjacent posns for paper rolls
                for(int k=0;k<8;k++)
                {
                    int r1 = i + dirn[k].first;
                    int c1 = j + dirn[k].second;

                    if(r1>=0 && r1<m && c1>=0 && c1<n)
                    {
                        if(grid[r1][c1]=='@') {count++;}
                    }
                }

                if(grid[i][j]=='@' && count<4) 
                {
                    //remove it in new grid
                    temp_grid[i][j] = '.';
                    ans++;
                }
            }
        }

        if(ans==0) {break;} //no more paper rolls to remove

        grid = temp_grid;
        res += ans;
    }
    

    cout<<res<<endl;
}