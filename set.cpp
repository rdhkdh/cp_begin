#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    set<int> s;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        int orig_size = s.size();
        s.insert(x);
        if(orig_size==s.size()) {cout<<x<<" ";}
    }
}