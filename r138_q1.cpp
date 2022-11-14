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

        int x[m],y[m];
        for(int i=0;i<m;i++)
        {
            cin>>x[i]>>y[i];
        }

        if(m<=n-1) {cout<<"YES\n";}
        else {cout<<"NO\n";}
        
    }
}