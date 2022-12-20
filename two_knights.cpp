#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    for(int k=1;k<=n;k++)
    {
        long long int x= pow(k,4)-(9*k*k)+(24*k)-16 ;
        x= x>>1;
        cout<<x<<endl;
    }
}