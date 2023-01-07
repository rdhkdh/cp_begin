#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;

    int a[]= {1,5,10,20,100};
    long long int count=0;

    for(int i=4;i>=0;i--)
    {
        count = count + (n/a[i]) ;
        n= n%a[i];
    }
    cout<<count<<endl;
}