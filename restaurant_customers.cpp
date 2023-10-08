#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int s,f;
    vector<pair<int,int>> v;

    for(int i=0;i<n;i++)
    {
        cin>>s>>f;
        v.push_back({s,1});
        v.push_back({f,-1});
    }
    sort(v.begin(),v.end());

    int curr_ppl=0,max_ppl=0;
    for(int i=0;i<v.size();i++)
    {
        curr_ppl += v[i].second;
        max_ppl= max(curr_ppl,max_ppl);
    }

    cout<<max_ppl<<endl;
}