#include<bits/stdc++.h>
using namespace std;

int main()
{
    string pi= "3141592653589793238462643383279";
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        int count=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==pi[i]) {count++;}
            else{break;}
        }
        cout<<count<<endl;

    }
}