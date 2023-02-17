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
        
        if(n<2020) {cout<<"NO\n";}
        else
        {
            if((n/2020)>=(n%2020)) {cout<<"YES\n";}
            else{cout<<"NO\n";}
        }
    }
}