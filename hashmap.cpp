#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    
    for(auto i: mp) //pointer
    {
        if(i.second==2) {cout<<i.first<<" ";}
    }
    cout<<endl;

    map<int,int>::iterator it=mp.begin();
    while(it!=mp.end()) //iterator
    {
        if(it->second==2)
            cout<<it->first<<" ";
        it++;
    }

    // mp.insert(pair<char,int> ('c',3));
    // mp.insert(pair<char,int> ('b',2));
    // for(auto i: mp)
    // {
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

}