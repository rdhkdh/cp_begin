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

        if(n==2) {cout<<"2 1"<<endl;}
        if(n==3) {cout<<-1<<endl;}

        if(n%2==0 && n>2)
        {
            for(int i=n;i>=1;i--) { cout<<i<<" "; }
            cout<<endl;
        }
        
        else if(n%2!=0 && n!=3)
        {
            for(int i=n;i>=(n+3)/2;i--) { cout<<i<<" "; }
            for(int i=1;i<=(n+1)/2;i++) { cout<<i<<" "; }
            cout<<endl;
        }
    }
}