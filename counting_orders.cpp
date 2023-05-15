#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++) {cin>>a[i];}
        for(int i=0;i<n;i++) {cin>>b[i];}
        sort(a,a+n);
        sort(b,b+n);

        int res=1;
        for(int i=0;i<n;i++)
        {
            int index = upper_bound(a, a+n, b[i]) - a;
            int x=(i+1-index);
            if(x>0) {res= (res*(x%mod))%mod; }
            else{res=0; break;}
        }
        
        cout<<res<<endl;
    }
}