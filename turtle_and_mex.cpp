#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t,n,m;
    cin>>t;

    while(t--)
    {   
        cin>>n>>m;

        int l;
        vector<int> a[n];
        for(int i=0;i<n;i++)
        {
            cin>>l;
            int x;
            for(int j=0;j<l;j++) 
            {
                cin>>x;
                a[i].push_back(x);
            }
        }

        vector<int> mex(n,-1);
        for(int i=0;i<n;i++)
        {
            vector<int> v = a[i];
            sort(v.begin(),v.end());

            int curr=0;
            for(int j=0; j<v.size(); j++)
            {
                if(v[j]==curr) {curr++;}
                else if(v[j]<curr) {continue;}
                else if(v[j]>curr) {break;}
            }

            mex[i] = curr;
        }

        int max_mex = *max_element(mex.begin(), mex.end());
        vector<int> max_indices;
        for(int i=0;i<n;i++)
        {
            if(mex[i]==max_mex)
            {
                max_indices.push_back(i);
            }
        }

        int max_max_mex = -1;
        for(auto max_index: max_indices)
        {
            vector<int> v = a[max_index];
            v.push_back(max_mex);
            sort(v.begin(),v.end());
            int curr=0;
            for(int j=0; j<v.size(); j++)
            {
                if(v[j]==curr) {curr++;}
                else if(v[j]<curr) {continue;}
                else if(v[j]>curr) {break;}
            }
            max_max_mex = max(curr, max_max_mex);
        }
        


        if(m<max_max_mex)
        {
            cout<<(m+1)*max_max_mex<<endl;
        }
        else
        {
            int y = (m*(m+1))/2;
            int z = (max_max_mex*(max_max_mex+1))/2;
            cout<<y+z<<endl;
        }
        


    }
}