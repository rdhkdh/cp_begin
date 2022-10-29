#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;

        if(c!='g')
        {
            s=s+s;
            
            vector<int> r,g,y;
            for(int i=0;i<2*n;i++)
            {
                if(s[i]=='r') {r.push_back(i);}
                if(s[i]=='g') {g.push_back(i);}
                if(s[i]=='y') {y.push_back(i);}
            }

            int diff=0;
            int max=diff;
            if(c=='r')
            {
                for(auto u: r)
                {
                    if(u<n)
                    {
                        diff= *upper_bound(g.begin(),g.end(),u) - u ;
                        if(diff>max) {max=diff;}
                    }
                }
                cout<<max<<endl;
            }

            diff=0;
            max=diff;
            if(c=='y')
            {
                for(auto u: y)
                {
                    if(u<n)
                    {
                        diff= *upper_bound(g.begin(),g.end(),u) - u ;
                        if(diff>max) {max=diff;}
                    }
                }
                cout<<max<<endl;
            }

            
        }

        if(c=='g') {cout<<0<<endl;}

    }
}