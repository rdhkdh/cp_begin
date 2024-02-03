#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    long long int sum=0, m; //m=min prefix sum
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    m=a[0];

    for(int i=0;i<n;i++)
    {
        sum += a[i];
        m = min(sum,m);
    }

    long long int initial;
    if(m>=0) {initial=0;}
    else{initial= -1*m;}

    //min no of intial passengers = -m
    cout<<initial+sum<<endl;
}