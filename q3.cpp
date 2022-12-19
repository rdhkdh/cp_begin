#include<bits/stdc++.h>
using namespace std;
int main()
{
    int optimum[9] = {1,2,4,7,11,16,22,29,37};
    int t;
    cin>>t;
    while(t--)
    {
        int k,n;
        cin>>k>>n;

        vector<int> v;

        int i;
        for(int i=0;i<k;i++)
        {
            if(optimum[i]>n) {break;}
            else{ v.push_back(optimum[i]); }
        }

        int s1=v.size();
        int last= v[s1-1];
        int og_last= v[s1-1];

        if(s1<k) 
        { 
            int count=0;
            int y=n;
            while( count!=(k-s1) )
            {
                if(binary_search(v.begin(),v.end(),y)==false)
                {v.push_back(y); count++;}
                y--;
            }
        }

        sort(v.begin(),v.end());
        for(auto x: v) {cout<<x<<" ";}
        cout<<endl;
    }
    
}