#include<bits/stdc++.h>
using namespace std;

int cyclic_perm(int arr[],int perm[],int n)
{
    int d_arr[2*n]; 
    for(int i=0;i<n;i++)
    {
        d_arr[i]=arr[i];
    }
    for(int i=n;i<2*n;i++)
    {
        d_arr[i]=arr[i-n];
    }

    int index;
    for(int i=0; i<2*n; i++)
    {
        if(perm[0]==d_arr[i]) {index=i; break;}
    }
    for(int j=index; j<index+n; j++)
    {
        if(d_arr[j]!=perm[j-index]) {return 0;}
    }
    return 1;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n; 
        cin>>n;
        int a[n],b[n];

        for(int i=0;i<n;i++) { cin>>a[i]; }
        for(int i=0;i<n;i++) { cin>>b[i]; }

        if(cyclic_perm(a,b,n)) {cout<<"b is cyclic permutation of a\n";}
        else{cout<<"b is not cyclic perm of a\n";}
    }

}