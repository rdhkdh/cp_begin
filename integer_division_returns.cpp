#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int x;
    cin>>x;

    if(x==0) {cout<<0<<endl; return 0;}
    if(x%10==0) {cout<<x/10<<endl; return 0;}

    if(x>0 && x<10)
    {
        cout<<1<<endl;
        return 0;
    }
    if(x<0 && x>-10)
    {
        cout<<0<<endl;
        return 0;
    }
    
    x = x/10;
    if(x>0) 
    {
        cout<<x+1<<endl;
    }
    else if(x<0)
    {
        cout<<x<<endl;
    }
    


    return 0;
}