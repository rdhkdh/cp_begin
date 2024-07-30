#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;

    cin>>t;

    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) {cin>>a[i];}

        int m = 0;
        for(int i=0;i<n;i+=2)
        {
            m = max(m,a[i]);
        }

        cout<<m<<endl;
    }
}