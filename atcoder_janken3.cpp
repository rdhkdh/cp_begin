#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int ans=0;

    char t[n];
    char win_char;
    
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R')
        {
            win_char = 'P';
        }
        else if(s[i]=='P')
        {
            win_char = 'S';
        }
        else if(s[i]=='S')
        {
            win_char = 'R';
        }   

        if(i==0) 
        {
            t[i] = win_char; 
            ans++; 
            continue;
        }

        if(t[i-1] != win_char) 
        {
            t[i] = win_char;
            ans++;
        }
        else if(t[i-1] == win_char)
        {
            t[i] = '0';
        }
        else if(t[i-1]=='0') 
        {
            t[i] = win_char;
            ans++;
        }
    }

    cout<<ans<<endl;
}