#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n],b[m];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>b[i];
        }

        sort(a,a+n);
        sort(b,b+m);

        for(int i=0;i<m;i++)
        {
            a[i%n]=b[i];
        }

        int sum=0;
        for(int i=0;i<n;i++) {sum+=a[i];}

        cout<<sum<<endl;
    }
}