#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int n;
    cin>>n;
    int a[n],b[n],p[n];
    
    for(int i=0;i<n;i++) { cin>>p[i]; }
    for(int i=0;i<n;i++) { cin>>a[i]; }
    for(int i=0;i<n;i++) { cin>>b[i]; }

    int m;
    cin>>m;
    int c[m];
    for(int i=0;i<m;i++) { cin>>c[i]; }

    for(int i=0;i<m;i++)
    {
        int flag=0;
        int min=1000000001; 
        for(int j=0;j<n;j++) 
        {
            if(c[i]==a[j] || c[i]==b[j]) 
            {
                flag=1;
                if(p[j]<min) {min=p[j];}
            }
        }
        if(flag==1) {cout<<min<<" "; }
        if(flag==0) {cout<<-1<<" ";}
    }
}