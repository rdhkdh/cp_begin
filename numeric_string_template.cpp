#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) {cin>>a[i];}

        int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            string s;
            cin>>s;

            if(s.length()!=n) {cout<<"NO"<<endl; continue;}
            
            map<char,int> mp;
            set<int> st;
            int flag=0;
            for(int i=0;i<n;i++)
            {
                st.insert(a[i]);
                if( mp[s[i]]==0 ) 
                {
                    mp[s[i]] = a[i];
                }
                else if(mp[s[i]] != 0 && mp[s[i]] != a[i])
                {
                    flag=1;
                    break;
                }
            }
            if(st.size()!=mp.size()) {cout<<"NO"<<endl; continue;}
            if(flag==1) {cout<<"NO"<<endl;}
            else{cout<<"YES"<<endl;}
        }
    }
}