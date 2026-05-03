#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    
    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {cin >> a[i];}
        
        vector<bool> dp(100 * n + 1, false);
        dp[0] = true;
        
        for (int i = 0; i < n; i++) 
        {
            int step = 100 / a[i];  
            vector<bool> new_dp = dp;
            
            for (int s = 0; s <= 100 * n; s++) 
            {
                if (dp[s]) 
                {
                    for (int subtasks = 1; subtasks <= a[i]; subtasks++) 
                    {
                        int new_score = s + subtasks * step;
                        if (new_score <= 100 * n) {
                            new_dp[new_score] = true;
                        }
                    }
                }
            }
            dp = new_dp;
        }
        
        bool possible = true;
        for (int k = 0; k <= 100 * n; k++) 
        {
            if (!dp[k]) 
            {
                possible = false;
                break;
            }
        }
        
        cout << (possible ? "Yes" : "No") << endl;
    }
    
    return 0;
}