#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int x=t;
    while(t--)
    {
        string s;
        cin>>s;
        
        if(s.back()=='a'||s.back()=='e'||s.back()=='i'||s.back()=='o'||s.back()=='u')
        {
            cout<<"Case #"<<x-t<<": "<<s<<" is ruled by Alice.\n";
        }
        else if(s.back()=='y')
        {
            cout<<"Case #"<<x-t<<": "<<s<<" is ruled by nobody.\n";
        }
        else{
            cout<<"Case #"<<x-t<<": "<<s<<" is ruled by Bob.\n";
        }
    }
}