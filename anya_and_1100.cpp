#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;
        int n = s.length();

        vector<char> str(n);
        for(int i=0;i<n;i++)
        {
            str[i] = s[i];
        }

        set<int> starting;
        for(int i=0;i<=n-4;i++)
        {
            string temp="";
            temp += s[i];
            temp += s[i+1];
            temp += s[i+2];
            temp += s[i+3];

            if(temp=="1100") 
            {
                starting.insert(i);
            }
        }

        int q;
        cin>>q;

        for(int i=0;i<q;i++)
        {
            int index, val;
            cin>>index>>val;

            index--;

            str[index] = val+48;

            for(int i=index-3;i<=index;i++)
            {
                if(i>n-4) {break;}
                string temp="";
                temp += str[i];
                temp += str[i+1];
                temp += str[i+2];
                temp += str[i+3];

                if(starting.find(i) != starting.end())
                {
                    if(temp!="1100")
                    {
                        starting.erase(i);
                    }
                }
                else
                {
                    if(temp=="1100") 
                    {
                        starting.insert(i);
                    }
                }
            }

            if(starting.size()!=0) {cout<<"YES\n";}
            else{cout<<"NO\n";}
        }
    }
}