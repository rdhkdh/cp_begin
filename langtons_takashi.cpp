#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h,w,n;
    cin>>h>>w>>n;

    char grid[h][w];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            grid[i][j]= '.';
        }
    }

    int curr_h=0,curr_w=0; //0-indexing used- diff from ques
    int dirn = 0; // assume CW order: 0=up, 1=right, 2=down, 3=left

    for(int i=1;i<=n;i++)
    {
        if(grid[curr_h][curr_w]=='.')
        {
            grid[curr_h][curr_w]='#';
            dirn = (dirn+1)%4; //cw rotn
            //move:
            switch(dirn)
            {
                case 0:
                curr_h = (h+curr_h-1)%h;
                break;

                case 1:
                curr_w = (curr_w+1)%w;
                break;

                case 2:
                curr_h = (curr_h+1)%h;
                break;

                case 3:
                curr_w = (w+curr_w-1)%w;
                break;
            }
        }
        else if(grid[curr_h][curr_w]=='#')
        {
            grid[curr_h][curr_w]='.';
            dirn = (4+dirn-1)%4; //acw rotn
            //move:
            switch(dirn)
            {
                case 0:
                curr_h = (h+curr_h-1)%h;
                break;

                case 1:
                curr_w = (curr_w+1)%w;
                break;

                case 2:
                curr_h = (curr_h+1)%h;
                break;

                case 3:
                curr_w = (w+curr_w-1)%w;
                break;
            }
        }
    }

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}