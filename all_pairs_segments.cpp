#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        int x[n];
        int k[q];
        for(int i=0;i<n;i++) {cin>>x[i];}
        for(int i=0;i<q;i++) {cin>>k[i];}

        map< int,  int> mp; // no of segments, no of points
        for(int i=1;i<n;i++)
        {
            int no_of_points = x[i]-x[i-1]-1;
            int no_of_segments = i*(n-i);
            if(mp.find(no_of_segments)==mp.end()) {mp[no_of_segments] = no_of_points;}
            else { mp[no_of_segments] += no_of_points; }
        }

        for(int i=0;i<n;i++)
        {
            int no_of_points = 1;
            int no_of_segments = (i*(n-1-i))+n-1;
            if(mp.find(no_of_segments)==mp.end()) {mp[no_of_segments] = no_of_points;}
            else { mp[no_of_segments] += no_of_points; }
        }

        for(int i=0;i<q;i++)
        {
            if(mp.find(k[i])==mp.end()) {cout<<0<<" ";}
            else{cout<<mp[k[i]]<<" ";}
        }
        cout<<endl;

    }
}