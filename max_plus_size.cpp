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

        int count_even=0,count_odd=0;
        int max_even=0,max_odd=0;
        for(int i=0;i<n;i+=2)
        {
            count_even ++;
            max_even = max(max_even,a[i]);
        }
        for(int i=1;i<n;i+=2)
        {
            count_odd ++;
            max_odd = max(max_odd,a[i]);
        }

        cout<<max(count_even+max_even, count_odd+max_odd)<<endl;
    }
}