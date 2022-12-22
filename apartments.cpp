#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n,m,k,y;
    cin>>n>>m>>k;
    vector<int> a;
    vector<int> b;
    for(int i=0;i<n;i++) {cin>>y; a.push_back(y);}
    for(int i=0;i<m;i++) {cin>>y; b.push_back(y);}

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int count=0,j=0;
    for(int i=0;i<n;i++)
    {
        while(j<m)
        {
            if(b[j]-k > a[i]) {break;}
            else if(b[j]+k<a[i]) {j++;}
            else{count++; j++; break;}
        }
    }

    cout<<count;
}