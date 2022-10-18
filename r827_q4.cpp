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

        int max=-3,flag=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                if( __gcd(a[i],a[j])==1 ) 
                {
                     
                    if(max<=i+j) {max=i+j;}
                }
            }
        }
        cout<<max+2<<endl;
    }   
    
}