#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;

    int n = s.length();
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        if(int(s[i])==int(t[i])) {v[i] = 0;}
        else if(int(s[i]) > int(t[i])) {v[i] = -1;}
        else if(int(s[i]) < int(t[i])) {v[i] = 1;}
    }

    vector<string> ans;
    for(int i=0; i<n; i++)
    {
        if(v[i]==-1) 
        {
            s[i] = t[i];
            ans.push_back(s);
        }
    }

    for(int i=n-1; i>=0; i--)
    {
        if(v[i]==1) 
        {
            s[i] = t[i];
            ans.push_back(s);
        }
    }

    cout<<ans.size()<<endl;
    for(auto u: ans)
    {
        cout<<u<<endl;
    }
}