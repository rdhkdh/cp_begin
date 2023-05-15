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
        int m=0;
        for(int i=0;i<n;i++) 
        {
            cin>>a[i];
            int x = abs(i+1-a[i]);
            if(x!=0) { m=__gcd(m,x); }
        }
        cout<<m<<endl;
    }
}