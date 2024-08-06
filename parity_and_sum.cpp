#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t,n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        vector<int> a(n), even, odd;
        for(int i=0;i<n;i++) 
        {
            cin>>a[i];
            if(a[i]%2==0) { even.push_back(a[i]); }
            if(a[i]%2==1) { odd.push_back(a[i]); }
        }

        if(odd.size()==0) {cout<<0<<endl; continue;}
        else if(even.size()==0) {cout<<0<<endl; continue;}

        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());

        int ops=0;
        int i=0;
        while(i<even.size())
        {
            int x = odd[odd.size()-1];
            if(even[i] < x)
            {
                odd.push_back(even[i]+x);
                i++;
                ops++;
            }
            else
            {
                odd[odd.size()-1] = even[i]+x;
                ops++;
            }
        }

        cout<<ops<<endl;
    }
}