#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin>>n;

    vector<pair<int,int>> v;

    int s,e;
    for(int i=0;i<n;i++)
    {
        cin>>s>>e;
        v.push_back(make_pair(s,e));
    }

    sort(v.begin(),v.end(), comp); //sort by end times

    int curr_end_time = v[0].second;
    int count = 1;
    int i = 1;
    while(i<n)
    {
        if(v[i].first >= curr_end_time)
        {
            count++;
            curr_end_time = v[i].second;
        }
        i++;
    }

    cout<<count<<endl;
    
}