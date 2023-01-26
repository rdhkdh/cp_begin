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
        int a[n];
        for(int i=0;i<n;i++) {cin>>a[i];}

        if(n==3) {}

        vector<int> odd,even; //stores index nos.
        int flag=0,index;
        for(int i=0;i<n;i++)
        {
            if(a[i]%2==0) {even.push_back(i);}
            if(a[i]%2==1) {odd.push_back(i);}
            if(odd.size()>=1 && even.size()>=2) {flag=1; break;}
            if(odd.size()==3) {flag=2; break;}
        }
        if(flag==0) {cout<<"NO\n";}
        if(flag==1) 
        {
            cout<<"YES\n";
            cout<<odd[0]+1<<" "<<even[0]+1<<" "<<even[1]+1<<endl;
        }
        if(flag==2)
        {
            cout<<"YES\n";
            cout<<odd[0]+1<<" "<<odd[1]+1<<" "<<odd[2]+1<<endl;
        }

    }
}