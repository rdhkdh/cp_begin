#include<bits/stdc++.h>
using namespace std;
int v[256][256];

int main()
{
    int current=0;
    for(int i=0;i<256;i+=2)
    {
        for(int j=0;j<256;j+=2)
        {
            v[i][j]=current;
            v[i][j+1]= current+1;
            v[i+1][j]=current+2;
            v[i+1][j+1]=current+3;
            current+=4;
        }
    }

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        cout<<n*m<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }

    }
}