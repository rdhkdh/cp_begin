#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string str;
        cin>>str;
        set<char> set1;
        for(int i=0;i<str.size();i++)
        {
            set1.insert(str[i]);
        }
        cout<<set1.size()<<endl;
    }

}
