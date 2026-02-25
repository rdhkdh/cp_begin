#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        string s,q;
        cin>>s>>q;

        sort(s.begin(),s.end());
        sort(q.begin(),q.end());

        if(s==q) {cout<<"YES\n";}
        else{cout<<"NO\n";}

        
    }
    return 0;
}