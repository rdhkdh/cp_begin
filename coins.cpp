#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int gcd;
        if(k%2==0) {gcd=2;}
        else{gcd=1;}

        
        (n%gcd==0) ? cout<<"YES\n" : cout<<"NO\n" ;

    }
}