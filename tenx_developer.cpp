#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n,a,b;
    cin>>n>>a>>b;

    vector<int> v(n);
    for(int i=0;i<n;i++) {cin>>v[i];}

    int ans = INT_MIN;

    while(true)
    {
        auto it1 = max_element(v.begin(),v.end());
        auto it2 = min_element(v.begin(),v.end());

        if(*it2 > ans) 
        {
            ans = *it2;
        }
        else
        {
            break;
        }

        v[it2-v.begin()] += a;
        v[it1-v.begin()] -= b;
    }
    cout<<ans<<endl;
}