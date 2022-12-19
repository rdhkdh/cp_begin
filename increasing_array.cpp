#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int moves=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1]) 
        { 
            moves+= (a[i-1]-a[i]);
            a[i]= a[i-1];
        }
    }
    cout<<moves;
}