#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,q;
        cin>>n>>q;

        long long int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int x[q],type[q];
        for(int i=0;i<q;i++)
        {
            cin>>type[i]>>x[i];
        }

        long long int sum=0;
        for(int i=0;i<n;i++) { sum+=a[i]; }

        int even=0,odd=0;
        for(int i=0;i<n;i++) 
        { 
            if(a[i]%2==0) {even++;}
            if(a[i]%2==1) {odd++;}
        }

        for(int i=0;i<q;i++)
        {
            if(type[i]==0)
            {
                sum+= (even*x[i]);
                if(x[i]%2==1) {odd+=even; even=0;}
                
            }

            if(type[i]==1)
            {
                sum+= (odd*x[i]);
                if(x[i]%2==1) {even+=odd; odd=0;}
            }

            cout<<sum<<endl;
        }

    }   
}