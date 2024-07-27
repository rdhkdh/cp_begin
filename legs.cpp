#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        int x = n%4;
        int y = (n - x)/4;
        int ans = y+ (x/2);

        cout<<ans<<endl;
    }
}