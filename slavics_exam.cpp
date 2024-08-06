#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    string s,t;
    cin>>T;

    while(T--)
    {
        cin>>s>>t;
        int i=0,j=0,slen=s.length(),tlen=t.length();

        while(i<slen && j<tlen)
        {
            if(t[j]==s[i] || s[i]=='?')
            {
                if(s[i]=='?')
                {
                    s[i] = t[j];
                }
                j++; i++;
            }
            else
            {
                i++;
            }
        }

        if(j<tlen)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            for(int i=0;i<slen;i++)
            {
                if(s[i]=='?') {s[i]='z';}
            }
            cout<<s<<endl;
        }

    }
}