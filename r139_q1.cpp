#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int d= floor(log10(n)+1);
        int m= n/pow(10,d-1);
        cout<<9*(d-1)+m<<endl;
    }
}