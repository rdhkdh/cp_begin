#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t,l,r;
    cin>>t;

    while(t--)
    {
        cin>>l>>r;

        
        // double x11 = log(l)/log(3); 
        // int x1 = floor(x11);            // [log3(l)]

        // double x22 = log(r)/log(3);
        // int x2 = floor(x22);             // [log3(r)]

        // int ans = 0;
        // ans += x1;
        // ans += (r-l+2);

        // int p = pow(3, x1+1);
        // for(int k=x1+1;k<=x2-1;k++)
        // {
        //     ans += (2*k*p);
        //     p = p*3;
        // }

        // ans += (x2*(r+1-pow(3,x2)));
        // ans += (x1*(pow(3,x1+1)-l));

        int ans=0;
        double temp11;
        int temp1;
        for(int i=l;i<=r;i++)
        {
            temp11 = (double)log(i)/(double)log(3); 
            temp1 = floor(temp11);

            ans += temp1;
            if(i==l) {ans += temp1;}
        }
        ans += (r-l+2);

        cout<<ans<<endl;
    }
}