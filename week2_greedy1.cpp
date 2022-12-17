#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,d,m;
    cin>>t>>d>>m;

    if(d<t) {cout<<"N\n";}

    vector<int> v;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    v.push_back(d);

    int last=0;  
    bool flag=false;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]-last>=t) {flag = true; break;}
        last=v[i];
    }  
    (flag)? cout<<"Y\n" : cout<<"N\n";

    

}
