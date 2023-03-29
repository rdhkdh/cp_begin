#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++) {cin>>a[i];}
    for(int i=0;i<m;i++) {cin>>b[i];}

    int i=0,j=0,current=1,flag;
    while(i<n && j<m)
    {
        if(a[i]<b[j]) {flag=1;} //using original values for comparison
        if(b[j]<a[i]) {flag=0;}

        if(flag==1) {a[i]=current; i++; current++; }
        if(flag==0) {b[j]=current; j++; current++; }

    }
    if(i==n) //b is incompletely assigned
    {
        for(int k=j; k<m;k++)
        {
            b[k]=current; current++;
        }
        
    }
    if(j==m) //a is incompletely assigned
    {
        for(int k=i; k<n;k++)
        {
            a[k]=current; current++;
        }
    }

    for(int k=0;k<n;k++) {cout<<a[k]<<" ";}
    cout<<"\n";
    for(int k=0;k<m;k++) {cout<<b[k]<<" ";}
    cout<<"\n";

    return 0;
}