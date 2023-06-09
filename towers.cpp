#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int k[n];
    for(int i=0;i<n;i++) {cin>>k[i];}

    multiset<int> towers;
    towers.insert(k[0]);
    for(int i=1;i<n;i++)
    {
        auto it = towers.upper_bound(k[i]);
        if(it!=towers.end())
        {
            towers.erase(it); 
            towers.insert(k[i]);
        }
        else{
            towers.insert(k[i]);
        }
    }
    cout<<towers.size();
}