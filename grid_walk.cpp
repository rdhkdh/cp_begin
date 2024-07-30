#include<bits/stdc++.h>
using namespace std;

bool check(int x, int y, int H, int W, vector<string> C)
{
    if(x<0 || y<0 || x>=H || y>=W || C[x][y]=='#')
    {
        return false;
    }

    return true;
}

int main()
{
    int H,W;
    cin>>H>>W;

    int sx,sy;
    cin>>sx>>sy;
    sx--; sy--; //following 0-based indexing

    vector<string> C(H);
    for(int i=0;i<H;i++)
    {
        cin>>C[i];
    }

    string X;
    cin>>X;

    for(auto c: X)
    {
        switch(c)
        {
            case 'L':
            if(check(sx,sy-1,H,W,C)) 
            {
                sx = sx;
                sy = sy-1;
            }
            break;

            case 'R':
            if(check(sx,sy+1,H,W,C)) 
            {
                sx = sx;
                sy = sy+1;
            }
            break;

            case 'U':
            if(check(sx-1,sy,H,W,C)) 
            {
                sx = sx-1;
                sy = sy;
            }
            break;

            case 'D':
            if(check(sx+1,sy,H,W,C)) 
            {
                sx = sx+1;
                sy = sy;
            }
            break;
        }
    }

    cout<<sx+1<<" "<<sy+1<<endl;
}