#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        if(n%2==1) {cout<<(n>>1)+1<<endl;}
        else {cout<<(n>>1)<<endl;}
    }
}