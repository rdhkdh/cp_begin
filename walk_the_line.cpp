#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("walk_the_line_input.txt","r",stdin);
    freopen("walk_the_line_output.txt","w",stdout);

    int t,n;
    long long int s,k;
    cin>>t;
    int og = t;

    while(t--)
    {
        cin>>n>>k;

        if(n==1)
        {
            cin>>s;
            if(s<=k) {cout<<"Case #"<<og-t<<": "<<"YES"<<endl;}
            else{cout<<"Case #"<<og-t<<": "<<"NO"<<endl;}
            continue;
        }

        long long int m = INT_MAX;
        for(int i=0;i<n;i++) 
        {
            cin>>s;
            m = min(s,m);
        }

        long long int temp= (2*n - 3)*m;
        if(temp <= k) {cout<<"Case #"<<og-t<<": "<<"YES"<<endl;}
        else{cout<<"Case #"<<og-t<<": "<<"NO"<<endl;}
    }
}