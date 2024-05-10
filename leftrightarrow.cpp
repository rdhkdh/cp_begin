#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int f1=0,f2=0;

    int n= s.length();
    if(s[0]=='<' && s[n-1]=='>') {f1=1;}
    else{cout<<"No\n"; return 0;}
    

    for(int i=1;i<=n-2;i++)
    {
        if(s[i]!='=') {cout<<"No\n"; return 0;}
    }

    cout<<"Yes\n";

    return 0;
}