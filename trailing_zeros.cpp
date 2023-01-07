#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int k= floor(log(n)/log(5));
    int sum=0;
    int y=n/5;

    for(int i=1;i<=k;i++)
    {
        sum+= y;
        y=y/5;
    }
    cout<<sum;
}