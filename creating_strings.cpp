#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    string s_sorted=s;
    sort(s.begin(),s.end());
    sort(s_sorted.begin(),s_sorted.end()); //not to change

    set<string> result;
    do
    {
        result.insert(s);
        next_permutation(s.begin(),s.end());
    } 
    while(s!=s_sorted);

    cout<<result.size()<<endl;
    for(auto u:result) {cout<<u<<endl;}
    
}