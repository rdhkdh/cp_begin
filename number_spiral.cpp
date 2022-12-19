#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int y,x; //row, col
        cin>>y>>x;

        long long int k;
        if(y>x) 
        {
            k= y; //max
            (k%2==0) ? cout<<(k*k)-x+1 : cout<<((k-1)*(k-1))+x ;
        }
        else 
        {
            k= x; //max
            (k%2==0) ? cout<<((k-1)*(k-1))+y : cout<<(k*k)-y+1 ;
        }
        cout<<endl;
    }
}
