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

        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin >>arr[i];
        }

        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==*max_element(arr,arr+n)) {cout<<i+1<<endl; break;}
        }
        
    }
}