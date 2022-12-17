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
        string s;
        cin>>s;

        if(n<=3) {cout<<"NO\n";}
        else{
            vector<char> v;
            for(int i=0;i<n;i++)
            {
                v.push_back(s[i]);
            }
            sort(v.begin(),v.end());

            vector<char> repeated;
            for(int i=0;i<n-1;i++)
            {
                if(v[i]==v[i+1]) 
                { 
                    if( !binary_search(repeated.begin(),repeated.end(),v[i]) )
                        repeated.push_back(v[i]); 
                }
            }

            int flag;
            for(int i=0;i<repeated.size();i++)
            {
                flag=0;
                int j;
                char nxt;
                for(j=0;j<n-1;j++)
                {
                    if(s[j]==repeated[i]) {nxt= s[j+1]; break;}
                }
                for(int k=j+2;k<n-1;k++)
                {
                    if(s[k]==repeated[i] && s[k+1]==nxt) {flag=1; break;}
                }
                if(flag==1) {break;}
            }

            (flag==1) ? cout<<"YES\n" : cout<<"NO\n" ;
        }
    }
}