#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    int s1=0,index;
    for(int i=n-1;i>=0;i--)
    {
        s1+=a[i];
        if(s1>(sum/2)) {index=i; break;}
    }
    cout<<n-index;
}