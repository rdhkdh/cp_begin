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
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        (sum%n==0) ? cout<<"0\n" : cout<<"1\n" ;

    }
}