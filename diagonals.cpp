#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;

        if(k==0) {cout<<0<<endl; continue;}

        int sum = 0, count=0;
        
        if(k>n)
        {
            k -= n;
            count++;
        }
        else // k<=n
        {
            cout<<1<<endl;
            continue;
        }

        for(int i=n-1;i>=1;i--)
        {
            if(k > 2*i)
            {
                k -= (2*i);
                count+=2;
            }
            else if(i < k && k <= 2*i )
            {
                k = 0;
                count+=2;
                break;
            }
            else if(0 < k && k <= i)
            {
                k = 0;
                count++;
                break;
            }
        }

        cout<<count<<endl;
    }
}