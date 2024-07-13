#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,m,k;
    cin>>t;

    while(t--)
    {
        cin>>n>>m>>k;
        
        for(int i=n;i>=k;i--)
        {
            cout<<i<<" ";
        }
        for(int i=m+1;i<=k-1;i++)
        {
            cout<<i<<" ";
        }
        for(int i=1;i<=m;i++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}