#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;

    int type=0;
    int x=0;
    unordered_map<int,int> mp;

    int count=0;
    while(q--)
    {
        cin>>type;

        if(type==1) 
        {
            cin>>x;

            if(mp[x]==0) {count++;}
            mp[x]++;
        }
        else if(type==2) 
        {
            cin>>x;

            if(mp[x]==1) {count--;}
            mp[x]--;
        }
        else if(type==3)
        {
            cout<<count<<endl;
        }
    }
}