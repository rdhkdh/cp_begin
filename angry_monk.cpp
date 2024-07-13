#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,k;
    cin>>t;

    while(t--)
    {
        cin>>n>>k;

        int a[k];
        for(int i=0;i<k;i++)
        {
            cin>>a[i];
        }
        sort(a,a+k);

        long long int sum=0;
        for(int i=0;i<k-1;i++)
        {
            sum += a[i];
        }

        long long int ans = 2*sum-k+1;
        cout<<ans<<endl;
    }

}