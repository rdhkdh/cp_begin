#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    int n;
    while(t--)
    {
        cin>>n;
        int a[n+1];

        int m=0;
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
            if(i!=n) {m = max(m,a[i]);}
        }

        cout<<m+a[n]<<endl;
        
    }
}