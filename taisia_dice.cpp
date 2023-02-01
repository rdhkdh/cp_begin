#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s,r;
        cin>>n>>s>>r;
        int a[n+1];
        a[n]=s-r;

        int g= r/(n-1);
        for(int i=1;i<=n-1;i++)
        {
            a[i] = g;
        }
        r=r-(n-1)*g;

        for(int i=1;i<=r;i++)
        {
            a[i]++;
        }
        for(int i=1;i<=n;i++) {cout<<a[i]<<" ";}
        cout<<endl;
    }
}