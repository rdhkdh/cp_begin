#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    string s;
    cin>>t;

    while(t--)
    {
        cin>>n;
        s = to_string(n);
        if(s.length()<3) {cout<<"NO"<<endl; continue;}

        if(s[0]=='1' && s[1]=='0' && s[2]!='0')
        {
            string x = s.substr(2);
            int y = stoi(x);
            if(y>=2)
            {
                cout<<"YES"<<endl;
                continue;
            }
            else{
                cout<<"NO\n";
                continue;
            }
        }
        cout<<"NO\n";
    }
}