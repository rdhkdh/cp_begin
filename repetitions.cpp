#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;

    int count=1;
    int max= count;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]==s[i-1]) {count++;}
        else{count=1;}
        if(count>max) {max= count;}
    }
    cout<<max;
}