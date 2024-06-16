#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    int n,m;
    while(t--)
    {
        cin>>n;
        int a[n],b[n];

        for(int i=0;i<n;i++) {cin>>a[i];}
        for(int i=0;i<n;i++) {cin>>b[i];}

        cin>>m;
        int d[m];
        for(int i=0;i<m;i++) {cin>>d[i];}

        vector<int> diff;
        for(int i=0;i<n;i++)
        {   
            if(a[i]!=b[i])
            {
                diff.push_back(b[i]);
            }
        }

        if(diff.size()==0)
        {
            if(find(b,b+n,d[m-1]) != b+n)
            {
                cout<<"YES"<<endl; return 0;
            }
            else{
                cout<<"NO"<<endl; return 0;
            }
        }

        sort(diff.begin(),diff.end());

        int flag=0;
        int i,last_no;
        for(i=0;i<m;i++)
        {
            auto ptr = find(diff.begin(),diff.end(),d[i]);
            if(ptr!=diff.end())
            {
                diff.erase(ptr);
            }

            if(diff.size()==0)
            {
                break;
            }
        }
        

        if(diff.size()==0)
        {
            if(find(b,b+n,d[m-1]) != b+n)
            {
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }

    }
}