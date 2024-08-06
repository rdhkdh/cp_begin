#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int n,s,m;
    cin>>t;

    while(t--)
    {
        cin>>n>>s>>m;

        int l[n],r[n];
        for(int i=0;i<n;i++)
        {
            cin>>l[i]>>r[i];
        }

        if(l[0] >= s) {cout<<"YES"<<endl; continue;}
        if(m-r[n-1] >= s) {cout<<"YES"<<endl; continue;}
        
        long long int diff=0;
        int flag=0;
        for(int i=1;i<n;i++)
        {
            diff = l[i]-r[i-1];
            if(diff>=s)
            {
                flag=1;
                break;
            }
        }
        if(flag==1) {cout<<"YES"<<endl;}
        else{cout<<"NO"<<endl;}

    }
}