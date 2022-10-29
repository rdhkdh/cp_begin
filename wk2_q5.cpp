#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    string s;
    map<string,int> names;
    
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(names.find(s)==names.end())
        {
            names.insert( {s,0} );
            cout<<"OK\n";
        }
        else
        {
            names[s]++;
            s= s+to_string(names[s]);
            cout<<s<<endl;
        }
    }
}