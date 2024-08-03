#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    string s;

    while(t--)
    {
        cin>>s;

        string ans="";

        int flag=0;
        int index;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==s[i-1]) 
            {
                flag=1;
                index=i;
                break;
            }
        }

        if(flag==0)
        {
            int n= s.length();
            if(s[n-1]!='z')
            {
                s += char(int(s[n-1])+1);
            }
            else
            {
                s += 'a';
            }
            cout<<s<<endl;
            continue;
        }

        for(int i=0;i<index;i++)
        {
            ans += s[i];
        }

        if(s[index]!='z')
        {
            ans += char(int(s[index])+1);
        }
        else
        {
            ans += 'a';
        }

        for(int i=index;i<s.length();i++)
        {
            ans += s[i];
        }

        cout<<ans<<endl;
        
    }
}