#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n,b;
    int t;
    cin>>t;

    while(t--)
    {
        cin>>n>>b;
        int a[n];
        for(int i=0;i<n;i++) {cin>>a[i];}
        sort(a,a+n);

        int r = b%n;
        int q = b/n;
        if(r==0) 
        {
            cout<<q*a[n-1]<<endl;
            continue;
        }

        int x=0,y=0;
        x = q*a[n-1];
        y = (q+1)*a[r-1];

        cout<<max(x,y)<<endl;
    }
}