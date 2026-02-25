#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int t;
    int n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        int ans=0;

        if(n<=14)
        {
            for(int i=0;i<=n;i++)
            {
                if(i%3==i%5) {ans++;}
            }
        }
        else
        {
            for(int i=0;i<=14;i++)
            {
                if(i%3==i%5) {ans++;}
            }

            int q = n/15;
            int r = n%15;

            ans = (q*ans);

            for(int i=n-r;i<=n;i++)
            {
                if(i%3==i%5) {ans++;}
            }
        }

        cout<<ans<<endl;
    }
}