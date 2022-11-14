#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n; 
        cin>>n;

        int a[n],b[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }

        int sum_a=0,sum_b=0;
        for(int i=0;i<n;i++)
        {
            sum_a += a[i];
            sum_b += b[i];
        }
        cout<< sum_a+ sum_b - *max_element(b,b+n)<<endl;
    }   
}