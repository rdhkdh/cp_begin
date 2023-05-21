#include<bits/stdc++.h>
using namespace std;
int main()
{
    string A;
    int n;
    cin>>A>>n;

    if(n==1) {cout<<A;}
    else if(n==2) 
    {
        string s_even,s_odd;
        for(int i=0;i<A.length();i++)
        {
            if(i%2==0) { s_even=s_even+A[i]; }
            if(i%2==1) { s_odd=s_odd+A[i]; }
        }
        s_even=s_even+s_odd;
        cout<<s_even;
    }
    else
    {
        string arr[n];
        int current=0;
        int dirn=1;  // 1= fwd, 0=backward
        
        for(int i=0;i<A.length();i++)
        {
            if(dirn==1)
            {
                arr[current]= arr[current]+A[i];
                current++; dirn=1;
                if(current==n) {current=n-2; dirn=0; continue;}
            }
            if(dirn==0)
            {
                arr[current]= arr[current]+A[i];
                current--; dirn=0;
                if(current==0) {current=0; dirn=1; continue;}
            }
        }
        string res;
        for(int i=0;i<n;i++)
        {
            res=res+arr[i];
        }
        
        cout<<res;
    }
}