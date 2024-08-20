#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,m,k;
    cin>>t;

    while(t--)
    {
        cin>>n>>m>>k;
        cout<<min(k,n)*min(k,m)<<endl;
    }
}