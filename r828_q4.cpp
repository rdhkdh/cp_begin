#include<bits/stdc++.h>
using namespace std;

int highestPowerOf2(long long int n)
{
    return (n & (~(n - 1)));
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        long long int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        long long int product=1;
        for(int i=0;i<n;i++)
        {
            product=product*a[i];
        }

        int m= highestPowerOf2(product);
        

    }
}