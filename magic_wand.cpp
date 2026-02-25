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

        int even_flag=0;
        int odd_flag=0;

        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        //check if all are odd
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]%2==0) {flag=1; break;} //found an even no
        }

        //check if all are even
        int flag2=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]%2==1) {flag2=1; break;} //found an odd no
        }

        if(flag==0 || flag2==0) 
        {
            for(auto u: a) {cout<<u<<" ";}
        }
        else
        {
            sort(a.begin(),a.end());
            for(auto u: a) {cout<<u<<" ";}
            
        }
        cout<<endl;

    }

    return 0;

}