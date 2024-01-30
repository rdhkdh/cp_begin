#include<bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main()
{
    string str;
    int n;
    cin>>str;
    cin>>n;

    vector<ll> code;
    ll d;
    
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
        {
            d = int(str[i]);
            n++;
            n *= d;
        }
        else{
            d = int(str[i]);
        }

        code.push_back(d*n);
    }

    for(auto u: code)
    {
        cout<<u<<" ";
    }
}