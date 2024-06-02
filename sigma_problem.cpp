#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main()
{
    int n;
    cin>>n;
    int a[n];
    int mod=1e8;
    int s=0;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];

        s += a[i];
    }

    int ans = s*(n-1);
    cout<<ans<<endl;
}