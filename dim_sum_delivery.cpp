#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("dim_sum_delivery_input.txt","r",stdin);
    freopen("dim_sum_delivery_output.txt","w",stdout);

    int t,r,c,a,b;
    cin>>t;
    int og = t;

    while(t--)
    {
        cin>>r>>c>>a>>b;

        if(r>c) {cout<<"Case #"<<og-t<<": "<<"YES"<<endl;}
        else{cout<<"Case #"<<og-t<<": "<<"NO"<<endl;}
    }

}