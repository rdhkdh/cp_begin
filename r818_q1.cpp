#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        if(n>1) 
        {
            int count=(n/2)+(n/3);
            cout<<n+(2*count)<<endl;
        }
        else if(n==1)
        {cout<<1<<endl;}
        
        

    }
}