#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int h,t;
    multiset<int> s; //stores prices
    for(int i=0;i<n;i++) { cin>>h; s.insert(h); }

    for(int i=0;i<m;i++) 
    {
        cin>>t; //budget
        auto it= s.upper_bound(t);
        if(it==s.begin())
        { cout<<-1<<endl; }
        else
        {
            cout<<*(--it)<<endl;
            s.erase(it);
        }
    }


}