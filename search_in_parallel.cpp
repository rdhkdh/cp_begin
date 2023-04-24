#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s1,s2;
        cin>>n>>s1>>s2;

        vector<pair<int,int>> r;
        for(int i=1;i<=n;i++) { int x; cin>>x; r.push_back(make_pair(-x,i)); }
        sort(r.begin(),r.end());

        vector<int> a,b;
        if(s1!=s2)
        {
            int i=s1,j=s2;
            for(int k=0;k<n;k++)
            {
                if(i<=j) { a.push_back(r[k].second); i+=s1; continue;}
                if(j<i) { b.push_back(r[k].second); j+=s2; continue;}
                
            }
        }
        else
        {
            for(int k=0;k<n;k++)
            {
                if(k%2==0) {a.push_back(r[k].second); }
                else { b.push_back(r[k].second); }
            }
        }

        cout<<a.size()<<" ";
        for(auto u: a) {cout<<u<<" ";}
        cout<<endl;
        cout<<b.size()<<" ";
        for(auto u: b) {cout<<u<<" ";}
        cout<<endl;
    }
}