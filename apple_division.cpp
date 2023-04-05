#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int s=0,min=1e9+5; //s=w1+w2
    int p[n];
    for(int i=0;i<n;i++) {cin>>p[i]; s+=p[i]; }

    int w1=0;
    for(int i=0;i<n;i++)
    {
        w1+=p[i];
        
    }
}