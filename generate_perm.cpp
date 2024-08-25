#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;

    while (t--)
    {
        cin>>n;
        if(n%2==0) {cout<<-1<<endl; continue;}

        int a[n+1];
        a[1] = 1;
        for(int i=2;i<=n;i+=2)
        {
            a[i] = i+1;
            a[i+1] = i;
        }
        for(int i=1;i<=n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    
}