#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int flag,i,j,indicator,x,y;
        for( i=1;i<=n;i++)
        {
            indicator=0;
            for( j=1;j<=m;j++)
            {
                flag=0;
                if(i+2<=n && j+1<=m) {flag=1; continue;}
                if(i+2<=n && 1<=j-1) {flag=1; continue;}

                if(1<=i-2 && j+1<=m) {flag=1; continue;}
                if(1<=i-2 && 1<=j-1) {flag=1; continue;}

                if(i+1<=n && j+2<=m) {flag=1; continue;}
                if(i+1<=n && 1<=j-2) {flag=1; continue;}

                if(1<=i-1 && j+2<=m) {flag=1; continue;}
                if(1<=i-1 && 1<=j-2) {flag=1; continue;}

                if(flag==0) {indicator=1; y=j; break;}
            }
            if(indicator==1) { x=i; break;}
        }
        cout<<x<<" "<<y<<endl;

    }
}