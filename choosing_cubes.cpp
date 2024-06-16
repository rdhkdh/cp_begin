#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    int n,f,k;
    while(t--)
    {
        cin>>n>>f>>k;
        int a[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int golden_no = a[f-1];
        sort(a,a+n);
        reverse(a,a+n);

        if(a[k-1]==golden_no && a[k]!=golden_no)
        {
            cout<<"YES"<<endl;
        }
        else if(a[k-1]!=golden_no && a[k]==golden_no)
        {
            cout<<"NO"<<endl;
        }
        else if(a[k-1]==golden_no && a[k]==golden_no)
        {
            cout<<"MAYBE"<<endl;
        }
        else
        {
            if(a[k-1]>golden_no)
            {
                cout<<"NO"<<endl;
            }
            else if(a[k-1]<golden_no)
            {
                cout<<"YES"<<endl;
            }
        }
    }
}
