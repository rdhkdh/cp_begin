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

        for(int i=0;i<q;i++)
        {
            if(type[i]==0)
            {
                for(int j=0;j<n;j++)
                {
                    if(a[j]%2==0) { a[j]+= x[i]; }
                }
            }
            if(type[i]==1)
            {
                for(int j=0;j<n;j++)
                {
                    if(a[j]%2==1) { a[j]+= x[i]; }
                }
            }

            long long int sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=a[i];
            }
            cout<<sum<<endl;
        }

    }   
}