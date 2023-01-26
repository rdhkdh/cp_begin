#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin>>n;
    int a[n], prefix_sum[n];
    for(int i=0;i<n;i++) {cin>>a[i];}

    prefix_sum[0]= a[0];
    for(int i=1;i<n;i++)
    {
        prefix_sum[i]= prefix_sum[i-1]+a[i];
    }

    int cand,min_prefix_sum=0,result=-10e9;
    for(int i=0;i<n;i++)
    {
        cand= prefix_sum[i] - min_prefix_sum;
        result= max(cand,result);
        min_prefix_sum = min(min_prefix_sum,prefix_sum[i]);        
    }

    cout<<result<<endl;
}
    