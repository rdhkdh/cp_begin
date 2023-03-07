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
        int a[n];
        for(int i=0;i<n;i++) {cin>>a[i];}

        vector<int> cost;
        for(int i=0;i<n;i++)
        {
            int l=1,r=i+1; //l at back, r at beginning of sequence
            while(l<=r)
            {
                int m= (l+r)/2;
                if( a[i+1-m]>=m ) { l=m+1; }
                else { r=m-1; }
            }
            
            cost.push_back(r);
        }

        for(auto u: cost) {cout<<u<<" ";}
        cout<<endl;
    }
}