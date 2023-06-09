#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int k[n];
    for(int i=0;i<n;i++) {cin>>k[i];}

    if(n==1) {cout<<1<<endl; return 0;}

    map<int,int> mp;
    int i=0,j=1,length=0,temp=1;
    mp[k[0]]=1;
    while(j<n)
    {
        mp[k[j]]++; 
        if(mp[k[j]]==2)
        {
            length= max(length,temp);
            while(k[i]!=k[j]) {mp[k[i]]--; i++; temp--;}
            mp[k[i]]--; i++;
            j++;
        }
        else
        {
            temp++;
            length = max(length,temp);
            j++;
        }
        length= max(length,temp);
    }

    cout<<length<<endl;
}