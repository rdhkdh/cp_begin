#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int x[n];
    int count=1;

    
    for(int i=0;i<n;i++)
    {
        if(x[i]==0)
        {
            int temp=0;
            map<int,int> mp; //freq of elements
            int l=x[i-1], r=x[i+1];
            if(l!=0 && r!=0)
            {
                mp[l-1]++; mp[l]++; mp[l+1]++;
                mp[r-1]++; mp[r]++; mp[r+1]++;
                for(auto it=mp.begin(); it!=mp.end();it++)
                {
                    if(it->second==2) {temp++;}
                }
            }
            if(l!=0 &&  )
            
        }
    }

}