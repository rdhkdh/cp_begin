#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        string mat[n];
        for(int i=0;i<n;i++)
        {
            cin>>mat[i];
        }
        int r=0,d=0; // r = no of cols having R
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(int(mat[i][j])==int('D')) {d++; break;}
            }
        }
        for(int j=0;j<m-1;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(int(mat[i][j])==int('R')) {r++; break;}
            }
        }
        //cout<<m-1-r+n-1-d<<endl;
        if((m-1-r)+(n-1-d)>k) {cout<<"No\n";}
        else{cout<<"Yes\n";}
    }
    
}