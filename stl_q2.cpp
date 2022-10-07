#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v1;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        v1.push_back(x);
    }

    set<int> s1;
    vector<int> v2;

    for(auto it1= v1.rbegin(); it1 !=v1.rend(); it1--)
    {
        if( s1.find(*it1) ==s1.end()) { s1.insert(*it1); }
        v2.push_back(*it1);
    }

    for(auto it2=v2.rbegin(); it2 !=v2.rend(); it2--)
    {
        cout<<*it2<<" ";
    }
    cout<<endl;

}