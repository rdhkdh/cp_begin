#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int arr[2*n];
    for(int i=0;i<2*n;i++)
    {
        cin>>arr[i];
    }

    int predecessor[n];
    for(int i=0;i<n;i++)
    {
        predecessor[i]=0;
    }

    int count=0;
    int max=count;
    
    for(int i=0;i<2*n;i++)
    {
        if(predecessor[arr[i]]==1) {count--;}
        else {count++;}
        if(count>max) {max=count;}
        predecessor[arr[i]]=1;
    }

    cout<<max<<endl;
}