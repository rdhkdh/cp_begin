#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int n;
    cin>>n;

    pair<int,int> p[n];
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        p[i]= make_pair(y,x); //end,start
    }

    sort(p, p+n); //sorts by first element

    int current_end=-1,count=0;
    for(int i=0;i<n;i++)
    {
        if(p[i].second>=current_end) 
        {
            current_end=p[i].first;
            count++;
        }
        
    }
    cout<<count<<endl;
}