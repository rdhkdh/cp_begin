#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int p[n],q[n];
        for(int i=0;i<n;i++) {cin>>p[i];}
        string s;
        cin>>s;

        vector<int> liked;
        vector<int> disliked;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0') {disliked.push_back(p[i]);}
            else{liked.push_back(p[i]);}
        }

        sort(disliked.begin(),disliked.end());
        for(int i=0;i<disliked.size();i++)
        {
            auto it= find(p,p+n,disliked[i]);
            int index= it-p;
            q[index]= i+1;
        }

        sort(liked.begin(),liked.end());
        for(int i=0;i<liked.size();i++)
        {
            auto it= find(p,p+n,liked[i]);
            int index= it-p;
            q[index]= disliked.size()+i+1;
        }

        for(int i=0;i<n;i++) {cout<<q[i]<<" ";}
        cout<<endl;
    }
}