#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l,r;
    cin>>l>>r;

    if((l==0 && r==0) || (l==1 && r==1)) 
    {
        cout<<"Invalid"<<endl; 
        return 0;
    }

    if(l==1 && r==0)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    if(l==0 && r==1)
    {
        cout<<"No"<<endl;
        return 0;
    }
}