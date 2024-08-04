#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    int M;
    cin>>n>>M;

    int a[n];
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
    }

    sort(a,a+n);

    int sum = 0;
    int x = M/n; //k=0
    int i=0;
    int flag=0;
    for(i=0;i<n-1;i++)
    {
        sum += a[i];
        if(sum>=M)
        {
            flag=1;
            break;
        }

        int diff = M - sum;
        int ans = (int) diff/(n-i-1);
        x = max(x, ans);
    }

    //k=n
    if(flag==0) 
    {
        sum += a[n-1];
        if(sum<=M)
        {
            cout<<"infinite"<<endl; return 0;
        }
    }

    cout<<x<<endl;

}