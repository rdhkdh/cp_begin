#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cheeseburger_corollary_1_input.txt","r",stdin);
    freopen("cheeseburger_corollary_1_output.txt","w",stdout);

    int t,s,d,k;
    cin>>t;
    int og = t;

    while(t--)
    {
        cin>>s>>d>>k;

        if(2*s+2*d < k+1) {cout<<"Case #"<<og-t<<": "<<"NO"<<endl; continue;}
        if(s+2*d < k)  {cout<<"Case #"<<og-t<<": "<<"NO"<<endl; continue;}
        
        cout<<"Case #"<<og-t<<": "<<"YES"<<endl;
    }
}