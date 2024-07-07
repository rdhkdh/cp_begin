#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n,k;
    cin>>n>>k;

    vector<int> v;
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }

    sort(v.begin(),v.end());

    int m=INT_MAX;
    for(int x=0;x<=k;x++)
    {
        m = min(v[n-k+x-1]-v[x],m);
    }

    cout<<m<<endl;
}