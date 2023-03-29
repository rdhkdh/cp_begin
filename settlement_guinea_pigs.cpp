#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int b[n+1];
        int count=0;
        for(int i=1;i<=n;i++) {cin>>b[i]; if(b[i]==1) {count++;}}

        for(int i=2;i<=n;i++)
        {
            if(b[i]==2 && b[i]-1)
        }



    }
}