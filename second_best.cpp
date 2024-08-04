#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<pair<int,int>> v;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        v.push_back(make_pair(x,i));
    }

    sort(v.begin(),v.end());

    cout<<v[v.size()-2].second<<endl;
}