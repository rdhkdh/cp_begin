#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,m,k,w;
    string s;
    cin>>t;

    while(t--)
    {
        cin>>n>>m>>k;
        cin>>w;
        int a[w];
        for(int i=0; i<w; i++) {cin>>a[i];}
        sort(a,a+w);

        // case 1, smaller
        if(n-2*(k-1) <=0 && m-2*(k-1)  <=0)
        {
            
        }
    }
}