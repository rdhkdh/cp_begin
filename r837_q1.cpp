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
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        sort(a,a+n);
        int begin_no=0,end_no=0;

        for(int i=0;i<n;i++)
        {
            if(a[i]==a[0]) {begin_no++;}
            if(a[i]==a[n-1]) {end_no++;}
        }
        if(a[0]!=a[n-1])
        { cout<<2*begin_no*end_no<<endl; }
        else
        {
            cout<<begin_no*(begin_no-1)<<endl;
        }
    }
}