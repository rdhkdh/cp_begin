#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
# define maxn 4100

//naive prime checker
bool is_prime(int n)
{
    if(n==1) {return false;}
    else{
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0) {return false;}
        }
    }
    return true;
}

//modular exponentiation
int mod_exp(int b,int e)
{
    int result=1;
    while(e>0)
    {
        if(e%2==1) { result= (result*b) %mod; }
        b=(b*b)%mod;
        e=e>>1; //divide by 2
    }
    return result;
}

int dp[maxn][maxn],fact[maxn],fact_inv[maxn];
vector<pair<int,int>> primes;

// DP function, nite we,ve set all initial values to -1.
int f(int x,int y)
{
    if(dp[x][y]>=0) {return dp[x][y];}
    if(x==(int)primes.size()) {return dp[x][y]=(y==0);}
    //dp recurrence when prime not to be selected
    dp[x][y]= fact_inv[primes[x].second]*f(x+1,y)%mod;

    if(y>0) //dp recurrence when prime is to be selected
    {
        dp[x][y]= ( dp[x][y] + fact_inv[primes[x].second-1]*f(x+1,y-1) )%mod;
    }

    return dp[x][y];
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int a[2*n];
    for(int i=0;i<2*n;i++) {cin>>a[i];}
    sort(a,a+2*n);

    //no of occurences of each number
    vector<pair<int,int>> acomp; 
    for(int i=0;i<2*n;i++)
    {
        if(acomp.size()==0 || acomp.back().first!=a[i]) 
        { acomp.push_back({a[i],1}); }
        else{ acomp.back().second++; }
    }

    //factorials and inverses
    fact[0]=1;
    for(int i=1;i<maxn;i++) { fact[i]=fact[i-1]*i %mod; }
    fact_inv[0]=1;
    //using mod-2 by fermat's little thm. factorial and mod are coprime
    for(int i=0;i<maxn;i++) { fact_inv[i]= mod_exp(fact[i],mod-2); }


    //adding only primes for dp
    for(auto i : acomp)
    {
		if(is_prime(i.first)){ primes.push_back(i);}
	}
    memset(dp,-1,sizeof(dp));
    int res= f(0,n); // f is the dp function

    //contribution of non primes
    for(auto i : acomp)
    {
		if(!is_prime(i.first)) 
        {
			res = res * fact_inv[i.second] % mod;
		}
	}
    res = res * fact[n] % mod;
    cout<<res<<"\n";

    return 0;
}
