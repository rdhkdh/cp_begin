#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,a,b,r;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>r;
        cout<<abs(a*(~b)-b*(~a))<<endl;

    }
}