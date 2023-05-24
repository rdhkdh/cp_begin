#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int c[n];
    for(int i=0;i<n;i++) {cin>>c[i];}
    sort(c,c+n);
    
    long long int current=1; //min sum you cannot make using i=0 coins
    for(int i=0;i<n;i++)
    {
        if(c[i]<=current)
        {
            current+=c[i];
        }   
        else{
            break;
        }
    }

    cout<<current<<endl;
}