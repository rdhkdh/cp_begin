#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    map<char,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[s[i]];
        mp[s[i]]=mp[s[i]]+1;
    }

    char arr[n];
    char mid;
    int flag=0;
    int i=0,count=0;
    for(auto u = mp.begin(); u != mp.end(); u++)
    {
        if(u->second%2==1) {mid=u->first; u->second=u->second-1; count++;}
        if(n%2==0 && count>0) {flag=1; break;}
        if(n%2==1 && count>1) {flag=1; break;}
    }
    if(flag==0)
    {
        for(auto u = mp.begin(); u != mp.end(); u++)
        {
            while(u->second>0)
            {
                arr[i]=u->first; arr[n-1-i]=u->first;
                u->second=u->second-2;
                i++;
            }
        }
        if(n%2==1) {arr[n/2]=mid;}
    }
    

    if(flag==1) {cout<<"NO SOLUTION\n";}
    else{
        for(int i=0;i<n;i++) {cout<<arr[i];}
    }
    
}