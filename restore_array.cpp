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
        int b[n],a[n+1];
        for(int i=1;i<=n-1;i++) {cin>>b[i];}

        a[1]=b[1];
        for(int i=2;i<n;i++) {a[i]=min( b[i-1],b[i] );}
        a[n]=b[n-1];

        for(int i=1;i<=n;i++) {cout<<a[i]<<" ";}
        cout<<endl;
    }
}