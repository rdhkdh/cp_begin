#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        int b[n-1];
        for(int i=0;i<n-1;i++) {cin>>b[i];}

        int a[n];

        a[0]=b[0];

        int flag=0;
        for(int i=1;i<n-1;i++)
        {
            a[i] = b[i] | b[i-1];
            if(a[i] >= (1<<30)) 
            {
                cout<<-1<<endl;
                flag=1;
                break;
            }
        }
        if(flag==1) {continue;}

        a[n-1] = b[n-2];

        if(a[n-1]>= (1<<30))
        {
            cout<<-1<<endl;
            continue;
        }

        int flag1=0;
        for (int i = 0; i < n - 1; ++i) 
        {
            if ((a[i] & a[i+1]) != b[i])
            {
                flag1=1;
                cout<<-1<<endl;
                break;
            }
        }
        if(flag1==1) {continue;}

        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}
