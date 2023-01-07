#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin>>n;
    int x=1;

    for(int i=1;i<=n;i++) 
    {
        x= x<<1;
        x=x%1000000007;
    }
    
    cout<<x;
}