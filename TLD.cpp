#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;

    string temp="";
    int n= str.length();
    for(int i=n-1;i>=0;i--)
    {
        if(str[i]!='.')
        {
            temp+= str[i];
        }
        else{
            break;
        }
    }

    reverse(temp.begin(),temp.end());
    cout<<temp<<endl;
}