#include<bits/stdc++.h>
using namespace std;
int main()
{
    int L,n1,n2;
    cin>>L>>n1>>n2;
    pair<int,int> a[n1+1],b[n2+1]; //first=val, second=length

    for(int i=1;i<=n1;i++)
    {
        int v,l;
        cin>>v>>l;
        a[i]=make_pair(v,l);
    }
    for(int i=1;i<=n2;i++)
    {
        int v,l;
        cin>>v>>l;
        b[i]=make_pair(v,l);
    }

    int j=0;


}