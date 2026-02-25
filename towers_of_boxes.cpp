#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m,d;
        cin>>n>>m>>d;

        int x = d/m; //floor(d/m)
        int ans = (n + x) / (x + 1); //ceil(n/x+1)

        cout<<ans<<endl;
    }
}