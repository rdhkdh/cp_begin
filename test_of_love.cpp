#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,m,k;
    cin>>t;

    while(t--)
    {
        cin>>n>>m>>k;

        string a;
        cin>>a;
        int flag=1; //yes

        vector<pair<int,int>> v; //indices of distant log pairs
        //first pass
        int prev_index=-1;
        for(int i=0;i<=n;i++)
        {
            if(a[i]=='L' || i==n)
            {
                if(i-prev_index>m)
                {
                    v.push_back(make_pair(prev_index,i));
                }
                prev_index=i;
            }
        }

        int swim_len=0;
        for(auto u: v)
        {
            int start = u.first;
            int end = u.second;


            int q = start+m;
            for(int i=q;i<end;i++)
            {
                if(a[i]=='C')
                {
                    flag=0; //no
                    break;
                }
            }
            if(flag==0) {break;}

            if(swim_len+(end-start-m) > k)
            {
                flag=0;
            }
            else{
                swim_len += (end-start-m);
            }

            if(flag==0) {break;}
        }

        if(flag==0) {cout<<"NO\n";}

        if(flag==1) {cout<<"YES\n";}
    }
}