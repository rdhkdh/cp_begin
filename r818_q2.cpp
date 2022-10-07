#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,r,c;
        cin>>n>>k>>r>>c;

        char mat[n][n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat[i][j]='.';
            }
        }

        //coordinates in my matrix= (r-1,c-1)
        for(int rr=r-1; rr<n; rr=rr+k)
        {
            for(int cc=c-1; cc<n; cc=cc+k)
            {
                mat[rr][cc]='X';
            }
        }
        for(int rr=r-1; rr>=0; rr=rr-k)
        {
            for(int cc=c-1; cc>=0; cc=cc-k)
            {
                mat[rr][cc]='X';
            }
        }
        for(int rr=r-1; rr>=0; rr=rr-k)
        {
            for(int cc=c-1; cc<n; cc=cc+k)
            {
                mat[rr][cc]='X';
            }
        }
        for(int rr=r-1; rr<n; rr=rr+k)
        {
            for(int cc=c-1; cc>=0; cc=cc-k)
            {
                mat[rr][cc]='X';
            }
        }

        //printing matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<mat[i][j];
            }
            cout<<endl;
        }


    }
}


