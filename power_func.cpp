#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    int x,y,p;
    cin>>x>>y>>p;

    // int res = 1;
    //     while (y > 0) 
    //     {
    //         if (y % 2 == 1)
    //             res = (res%p) * (x%p);
    //             res=res%p;
    
    //         y = y >> 1;
    //         x = (x * x); 
    //         x=x%p;
    //     }
    // cout<<(res+p) % p<<endl;

    long long int res = 1;
    long long int x1=x;
        while (y > 0) 
        {
            if (y % 2 == 1)
                res = (res * x1)%p;
    
            y = y >> 1;
            x1 = (x1%p) * (x1%p);
            x1=x1%p;
        }
        cout<< (res+p) % p;
}