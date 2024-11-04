#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        int b,c;
        map<int,int> net_cost;
        for(int i=0;i<k;i++)
        {
            cin>>b>>c;
            net_cost[b] += c;
        }

        vector<int> v;
        for(auto u: net_cost)
        {
            v.push_back(u.second);
        }
        sort(v.rbegin(), v.rend());

        int sum=0;
        for(int i=0; i<min(n, (int)v.size()); i++)
        {
            sum += v[i];
        }
        cout<<sum<<endl;
    }
}



