#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++) { cin>>p[i];}
    sort(p,p+n);

    int k=p[n/2];
    int min_cost=0;
    for(int i=0;i<n;i++)
    {
        min_cost += abs(p[i]-k);
    }
    cout<<min_cost<<endl;
}