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

        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        string str;
        cin>>str;

        pair<int,char> p[n];
        for(int i=0;i<n;i++)
        {
            p[i]= make_pair(arr[i],str[i]);
        }

        int flag=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(p[i].first==p[j].first) 
                {
                    if(p[i].second != p[j].second) {flag=1; break;}
                }
            }
            if(flag==1) {break;}
        }
        if(flag==1) { cout<<"NO\n"; }
        else{cout<<"YES\n";}

    }   
}