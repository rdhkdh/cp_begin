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

        int rr,cc;
        for(rr=r-1,cc=c-1; rr>=0,cc<=n-1; rr--,cc++)
        {
            mat[rr][cc]='X';
        }
        if(rr==-1) 
        {
            rr=0;
            cc--;
            for(cc=cc;cc<=n-1;cc++)
            {
                
            }
        }

        for(rr=r-1,cc=c-1; rr<=n-1,cc>=0; rr++,cc--)
        {
            mat[rr][cc]='X';
        }
        if(rr==n-1) {}
        

    }
}