#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin>>n;
    int s=0,m=1e9+5; //s=w1+w2
    
    int p[n];
    for(int i=0;i<n;i++) {cin>>p[i]; s+=p[i]; }

    
    for(int i=0;i<(1<<n);i++)
    {
        int b=i;
        int w1=0;
        for(int j=1;j<=n;j++)
        {
            if(b%2==1) {w1+=p[n-j];}
            b=b/2;
        }
        m= min(m,abs(s-(2*w1)));
    }

    cout<<m<<endl;
}