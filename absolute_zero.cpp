#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) {cin>>a[i];}

        vector<int> operations;

        for(int r=1;r<=41;r++)
        {
            int flag=0;
            for(int i=0;i<n;i++) 
            {
                if(a[i]!=0) 
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0) 
            {
                break;
            }

            int x = *max_element(a,a+n);
            operations.push_back(x);

            for(int i=0;i<n;i++)
            {
                a[i] = abs(a[i]-x);
            }
        }

        if(operations.size()<=40)
        {
            cout<<operations.size()<<endl;
            for(auto u: operations) {cout<<u<<" ";}
            cout<<endl; 
        }
        else
        {
            cout<<-1<<endl;
        }
               
    }
}