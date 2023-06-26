#include<bits/stdc++.h>
using namespace std;
#define int long long

pair<int,int> check(int a[],int start, int n, int target)
{
    int flag=0;
    int j,k;
    for(j=start;j<n;j++)
    {
        for(k=j+1;k<n;k++)
        {
            if(a[k]==target-a[j]) { flag=1; break; }
        }
        if(flag==1) break;
    }
    if(flag==0) {j=-1; k=-1;}
    pair<int,int> p = make_pair(j,k);
    return p;
}

int32_t main()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++) {cin>>a[i];}

    int first_posn;
    int flag=0;
    pair<int,int> posn;
    for(int i=0;i<n;i++)
    {
        if(x>a[i])
        {
            posn = check(a,i+1,n,x-a[i]);
            if(posn.first!=-1) {first_posn=i; flag=1; break; }
        }
    }
    if(flag==0) {cout<<"IMPOSSIBLE\n";}
    if(flag==1) {cout<<first_posn+1<<" "<<posn.first+1<<" "<<posn.second+1<<endl;}

    return 0;
}
