#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; 
    cin>>t;

    while(t--)
    {
        int n; 
        cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
        }

        vector<int> s(a.begin()+1, a.end());
        sort(s.begin(), s.end());
        int m = s[(n-1)/2];
        
        vector<int> B(n+1,0), C(n+1,0);
        for(int i=1;i<=n;i++)
        {
            B[i] = B[i-1] + (a[i] >= m ? 1 : -1);
            C[i] = C[i-1] + (a[i] >  m ? 1 : -1);
        }
        
        const int NEG = -1e9;
        vector<int> dp(n+1, NEG);
        dp[0] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(((i-j) & 1) == 0) continue; 
                if(dp[j] == NEG) continue;
                if(B[i] > B[j] && C[i] < C[j])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        cout<<dp[n]<<"\n";
    }
    return 0;
}