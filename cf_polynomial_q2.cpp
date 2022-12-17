#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k,x,max=0;
        cin>>n>>m>>k;
        for(int i=0;i<m;i++)
        {
            cin>>x;
            if(x>max) {max=x;}
        }

        if(m<k) {cout<<"NO\n";}
        else
        {
            //int x;
            //int max=0;
            
            
            if(n%k==0) 
            {
                (n/k >= max) ? cout<<"YES\n" : cout<<"NO\n" ;
            } 
            else
            {
                ( (n/k)+1 >= max ) ? cout<<"YES\n" : cout<<"NO\n" ;
            }
        }
        
    }
}