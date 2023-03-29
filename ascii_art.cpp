#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h,w;
    cin>>h>>w;
    int mat[h][w];
    char res[h][w];

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]==0) { res[i][j]='.'; }
            else{
                res[i][j]= char(mat[i][j]+64);
            }
        }
    }

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cout<<res[i][j];
        }
        cout<<"\n";
    }
}