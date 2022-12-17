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
        for(int i=0;i<n;i++) 
        {
            cin>>a[i];
        }

        vector<int> unassigned;
        for(int i=1;i<=n;i++) {unassigned.push_back(i);}

        sort(a,a+n);

        int count=0;

        if(a[0]>=1 && a[0]<=n) 
        {
            auto it= unassigned.begin()+a[0]-1;
            unassigned.erase( it );
            
            for(int i=1;i<n;i++)
            {
                if(a[i]>=1 && a[i]<=n && a[i-1]!=a[i]) 
                {
                    auto it2= unassigned.begin()+a[i]-1;
                    unassigned.erase( it2 );
                }
                else
                {
                    int m=unassigned[0];
                    if(m<a[i]/2) {count++;}
                    else{count=-1; break;}
                }
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                int m=unassigned[0];
                if(m<a[i]/2) {count++;}
                else{count=-1; break;}
            }
        }

        

        cout<<count<<endl;
    }
}