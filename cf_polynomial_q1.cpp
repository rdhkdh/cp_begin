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

        int count;
        (s[0]=='1') ? count=1 : count=0 ;
        
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0') {cout<<'+';}
            if(s[i]=='1')
            {
                count++;
                (count%2==1) ? cout<<'+' : cout<<'-' ;
            }
        }
        cout<<endl;
    }
}