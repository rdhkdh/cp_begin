#include<bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("two_apples_a_day_input.txt","r",stdin);
    // freopen("two_apples_a_day_output.txt","w",stdout);

    int t,n;
    cin>>t;
    int og = t;

    while(t--)
    {
        cin>>n;
        int a[2*n-1];
        for(int i=0;i<n;i++) {cin>>a[i];}

        sort(a,a+2*n-1);

        int ans = INT_MAX;

        int pairsum = a[0]+a[2*n-2];
        int flag=0;
        for(int i=1;i<=n-2;i++)
        {
            if(a[i] + a[2*n-2-i] != pairsum)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            ans = min(ans, pairsum-a[n-1]);
        }

        
        pairsum = a[1]+a[2*n-2];
        flag=0;
        for(int i=2;i<=n-1;i++)
        {
            if(a[i] + a[2*n-1-i] != pairsum)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            ans = min(ans, pairsum-a[0]);
        }
        
        pairsum = a[0]+a[2*n-3];
        flag=0;
        for(int i=1;i<=n-2;i++)
        {
            if(a[i] + a[2*n-3-i] != pairsum)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            ans = min(ans, pairsum-a[2*n-2]);
        }
        
        if(ans==INT_MAX)
        {
            ans=-1;
        }

        
        cout<<"Case #"<<og-t<<": "<<ans<<endl;
    }

}