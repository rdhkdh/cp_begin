#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;i++) {cin>>a[i];}

        vector<bool> occupied(n+1, false);

        int x,flag=1; //flag=1: all followed
        occupied[a[1]] = true;
        for(int i=2;i<=n;i++)
        {
            x = a[i];
            occupied[x] = true;
            if(x>=2 && x<=n-1)
            {
                if(!occupied[x-1] && !occupied[x+1])
                {
                    flag=0;
                }
            }
            else if(x==1)
            {
                if(!occupied[2]) {flag=0;}
            }
            else if(x==n)
            {
                if(!occupied[n-1]) {flag=0;}
            }

            if(flag==0) {break;}
        }

        if(flag==0) {cout<<"NO"<<endl;}
        else{cout<<"YES"<<endl;}
    }
}