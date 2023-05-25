#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int c[n+1]; // checking uptill that element
    c[n]=0;

    for(int i=0;i<n;i++) 
    {
        cin>>a[i]; 
        c[i]=0;
    }

    int round=1;
    for(int i=0;i<n;i++)
    {
        c[a[i]]=1;
        if(a[i]<n && c[a[i]+1]==1) {round++;}
    }
    cout<<round<<endl;
}