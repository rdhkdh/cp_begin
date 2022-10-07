#include<bits/stdc++.h>
using namespace std;
#define int long long int

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

int32_t main()
{
    fstream fp2;
    fp2.open("consecutive_cuts_chapter_1_validation_input.txt",ios::in); //read mode
    fstream fp;
    fp.open("fb_q1_valdn.txt",ios::out); //write mode

    int t;
    fp2>>t;
    int x=t; //storing original value of t

    while(t--)
    {
        int n,k;
        fp2>>n>>k;
        int a[n],b[n];

        for(int i=0;i<n;i++) { fp2>>a[i]; }
        for(int i=0;i<n;i++) { fp2>>b[i]; }

        if(!cyclic_perm(a,b,n)) {fp<<"Case #"<<x-t<<": NO"<<endl;}
        else
        {
            
            if(k!=0) { fp<<"Case #"<<x-t<<": YES"<<endl; }
            else if(k==0) { fp<<"Case #"<<x-t<<": NO"<<endl; }
        }

    }

    fp.close();
    fp2.close();

}

