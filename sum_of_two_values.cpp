//sort and then use two pointer approach
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n,x;
    cin>>n>>x;

    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int y;
        cin>>y;
        v.push_back(make_pair(y,i)); //storing index no. too
    }

    sort(v.begin(),v.end()); //sorts based on first element

    int i=0,j=n-1;
    while(i<j)
    {
        if(v[i].first+v[j].first>x) { j--; }
        else if(v[i].first+v[j].first<x) { i++; }
        else { break; }
    }

    if(i<j) 
    { 
        if(v[i].second < v[j].second) { cout<<v[i].second+1<<" "<<v[j].second+1; }
        else { cout<<v[j].second+1<<" "<<v[i].second+1; }
    }
    else { cout<<"IMPOSSIBLE"; }

}