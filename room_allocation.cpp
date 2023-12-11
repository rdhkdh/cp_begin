#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int x,y;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end()); //sort by start times

    set<int> fin_times;
    int rooms=0;
    int min_fin_time=0;
    for(int i=0;i<n;i++)
    {
        if(min_fin_time<v[i].first) 
        {
            fin_times.erase(fin_times.begin());
            fin_times.insert(v[i].second);
        }
        else{
            rooms++;
        }
    }

    return 0;
}