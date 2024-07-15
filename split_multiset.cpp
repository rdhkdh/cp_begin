#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k)
{
    if(n==1) {return 0;}
    if(n<=k) {return 1;}

    int n_steps=0;

    if(n%k!=0)
    {
        int q = n/k;
        n_steps++;

        if(q<k) 
        {
            n_steps += q;
            int r = n%k;
            n_steps += solve(r,k);
        }
        else //q>=k
        {
            n_steps += (k-1);
            int r = n - (k*(k-1));
            n_steps += solve(r,k);
        }
    }
    else
    {
        n_steps = 1+(n/k); //1+q
    }
    


    return n_steps;
}

int main()
{
    int t;
    cin>>t;
    int n,k;
     
    while(t--)
    {
        cin>>n>>k;
        cout<<solve(n,k)<<endl;

    }
}