#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("historian_hysteria_input.txt", "r", stdin);

    vector<int> a,b;
    int x,y;

    while(cin>>x>>y)
    {
        a.push_back(x);
        b.push_back(y);
    }

    int n = a.size();

    map<int,int> mp; //num, freq: from list B
    for(int i=0;i<n;i++)
    {
        mp[b[i]]++;
    }

    long long int similarity=0;
    for(int i=0;i<n;i++)
    {
        if(mp.find(a[i]) != mp.end())
        {
            similarity += (a[i]*mp[a[i]]);
        }
    }
    cout<<similarity<<endl;
}