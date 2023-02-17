#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {cin>>a[i];}

    int max_length=0,current=1;
    for(int i=0;i<n-1;i++)
    {
        if(a[i+1]>=a[i]) {current++;}
        else{
            max_length= max(current,max_length);
            current=1;
        }
        max_length= max(current,max_length);
    }

    cout<<max_length;
}