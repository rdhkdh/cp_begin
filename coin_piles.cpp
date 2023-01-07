#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;

        if(a%3==0 && b%3==0) 
        {
            ( a==b ) ? cout<<"YES\n" : cout<<"NO\n" ;      
        }
        else if(a%3==1 && b%3==2) 
        {
            ( (a-1)==(b-2) ) ? cout<<"YES\n" : cout<<"NO\n" ;
        }
        else if(a%3==2 && b%3==1) 
        {
            ( (a-2)==(b-1) ) ? cout<<"YES\n" : cout<<"NO\n" ;
        }
        else{cout<<"NO\n";}
    }
}