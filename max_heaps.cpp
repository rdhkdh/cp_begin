#include<bits/stdc++.h>
using namespace std;
#define int long long

int fact(int n)
{
      if(n==0)
      return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = (res * i)%1000000007;
    return res;
}

int nCr(int n, int r)
{
    return (fact(n)%1000000007) / (((fact(r)%1000000007) * (fact(n - r)%1000000007))%1000000007);
}

int getLeft(int n)
{
    int l;
    int h = log(n)/log(2); //int h = log2[n];
    int m = 1<<h; //2^h
    int p = n-m+1;
    
    if( p>=(m/2) ) { l= m-1; }
    else { l= n-(m/2); }
    return l;
}

// int no_of_heaps(int n)
// {
//     if(n<=1) return 1;
//     if(dp[n]!=0) {return dp[n];}
//     //else calculate:
//     dp[n]= nCr(n-1,l) * dp[l] * dp[r];
//     return dp[n];
// }

int32_t main() {
    int n;
    cin>>n;

    if (n <= 1) cout<< 1;
    
    int dp[n+1]={0}; 
    
    dp[0]=1; dp[1]=1;
    for(int i=2;i<n+1;i++)
    {
        int l= getLeft(i);
        int r= i-1-l;
        if(dp[i]==0) dp[i]= ( (nCr(i-1,l)%1000000007)*dp[l]*dp[r] )%1000000007;
    }
    
    cout<< dp[n];
}
