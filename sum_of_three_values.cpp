#include<bits/stdc++.h>
using namespace std;
//#define int long long

pair<int,int> check(vector<pair<int,int>> v, int start, int end, int x)
{
    int i=start,j=end;
    while(i<j)
    {
        if(v[i].first+v[j].first>x) { j--; }
        else if(v[i].first+v[j].first<x) { i++; }
        else { break; }
    }

    if(i<j) { return make_pair(v[i].second,v[j].second); } //returning positions
    return make_pair(-1,-1); //not found
}

int32_t main()
{
    int n,x;
    cin>>n>>x;

    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) 
    {
        int temp;
        cin>>temp;
        v.push_back(make_pair(temp,i));
    }
    sort(v.begin(),v.end());

    int flag=0,posn;
    pair<int,int> p;
    for(int i=0;i<n;i++)
    {
        p= check( v, i+1, n-1, x-v[i].first );
        if(p.first==-1 && p.second==-1) {continue;}
        else{posn=v[i].second; flag=1; break;}
    }

    if(flag==1)
    { 
        int arr[3]; 
        arr[0]=posn; arr[1]=p.first; arr[2]=p.second;
        sort(arr,arr+3);
        cout<<arr[0]+1<<" "<<arr[1]+1<<" "<<arr[2]+1<<endl;
    }
    else{ cout<<"IMPOSSIBLE\n"; }

    return 0;
}
