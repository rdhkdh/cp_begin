#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main()
{
    int t;
    cin>>t;

    int n,a,b;
    while(t--)
    {
        cin>>n>>a>>b;
        //case 1
        int k=0;
        int y = k*(b-a) - (k*(k-1)/2) + n*a;
        int profit = y;

        //case 2
        k=min(n,b);
        y = k*(b-a) - (k*(k-1)/2) + n*a;
        profit = max(profit, y);

        double x = (1+2*(b-a))/2;
        //case 3
        k = floor(x);
        if(k>=0 && k<=min(n,b))
        {
            y = k*(b-a) - (k*(k-1)/2) + n*a;
            profit = max(profit, y);
        }
        

        //case 4
        k = ceil(x);
        if(k>=0 && k<=min(n,b))
        {
            y = k*(b-a) - (k*(k-1)/2) + n*a;
            profit = max(profit, y);
        }

        cout<<profit<<endl;
    }
}