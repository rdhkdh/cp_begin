#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    pair<int,int> book[n+1]; //prices, pages
    int h[n+1],s[n+1];
    for(int i=1;i<=n;i++) {cin>>h[i];}
    for(int i=1;i<=n;i++) {cin>>s[i];}
    for(int i=1;i<=n;i++) {book[i]=make_pair(h[i],s[i]);}
    sort(book+1,book+n+1);

    int dp[n+1]; //max no of pages by selecting from 1,2...ith books
    dp[0]=0;
    int price=0; //current money used up
    for(int i=1;i<=n;i++)
    {
        if(price+book[i].first>x) {dp[i]=dp[i-1];}
        else{
            dp[i]= max( dp[i-1], dp[i-1]+book[i].second );
            if(dp[i]!=dp[i-1]) { price+=book[i].first; }
        }
    }

    cout<<dp[n]<<endl;
}