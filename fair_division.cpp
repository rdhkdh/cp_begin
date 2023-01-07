#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,count1=0,count2=0,net_wt;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x==1) { count1++; }
        }
        count2= n-count1;

        //net_wt = (2*count2) + count1;
        if(count1%2==1) {cout<<"NO\n";} //net wt is odd
        else{
            if(count2%2==0)
            {
                cout<<"YES\n";
            }
            else{
                if(count1>=2) {cout<<"YES\n";}
                else{cout<<"NO\n";}
            }
        }
    }
}