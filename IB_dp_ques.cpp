#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> A={0,1,5};
    int B=1,C=2;

    int result=0,z=0;
    string c = to_string(C);
    int n=c.length(),a=A.size();
    
    for(int i=0;i<a;i++) {if(A[i]==0) z++;}
    
    if(B>n) {result= 0;}
    else if(B<n)
    {
        result = a-z;
        for(int i=1;i<B;i++)
        {
            result = result*(a-i);
        } 
    }
    else
    {
        int dp[n+1],count;
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            count=0;
            for(int j=0;j<a;j++) 
            {
                if( A[j]< int(c[i-1])-48 ) {count++;} 
            }
            dp[i]= (dp[i-1]*(a-i+1)) + count;
        }
        result = dp[n];
    }

    cout<<result;
}