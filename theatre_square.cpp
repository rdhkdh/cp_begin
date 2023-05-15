#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n,m,a,x,y;
    cin>>n>>m>>a;
    if(m%a!=0) {x=((m-1)/a)+1; }
    else{x=m/a;}
    if(n%a!=0) {y=((n-1)/a)+1; }
    else{y=n/a;}
    cout<<x*y<<endl;
}