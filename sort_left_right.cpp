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

        vector<int> p(n);
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
        }

        vector<int> a = p;
        sort(a.begin(),a.end());
        if(p==a)
        {
            cout<<0<<endl;
            continue;
        }

        int flag=0;
        int index=0;
        int max_so_far=0;
        for(int i=0;i<n;i++)
        {
            max_so_far = max(max_so_far, p[i]);
            if(p[i]==i+1 && max_so_far==p[i]) //at right place and all preceding elems are smaller
            {
                flag=1;
                break;
            }
        }
        if(flag==1) 
        { 
            cout<<1<<endl;
            continue; 
        }

        if(p[0]!=n || p[n-1]!=1)
        {
            cout<<2<<endl;
            continue;
        }

        if(p[0]==n && p[n-1]==1)
        {
            cout<<3<<endl;
            continue;
        }


    }
}