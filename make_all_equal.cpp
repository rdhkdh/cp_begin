#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        int a[n];

        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }
        
        int m = 0;
        for(auto u: mp)
        {
            m = max(m, u.second); //max freq
        }

        cout<<n-m<<endl;
    }
}