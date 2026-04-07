#include <bits/stdc++.h>
using namespace std;

long long countPairs(long long S, long long x2) {
    if (S >= x2) return 0;
    long long N = x2 - 1;
    long long M = (N - S) / 2;
    
    const int BITS = 19;
    long long dp[2][2] = {};
    dp[1][1] = 1;
    
    for (int b = BITS; b >= 0; b--) {
        long long ndp[2][2] = {};
        int nBit = (N >> b) & 1;
        int mBit = (M >> b) & 1;
        int inS  = (S >> b) & 1;
        
        for (int tc = 0; tc < 2; tc++) {
            for (int tk = 0; tk < 2; tk++) {
                if (!dp[tc][tk]) continue;
                for (int v = 0; v <= 1; v++) {
                    if (tc && v > nBit) continue;
                    int new_tc = tc & (v == nBit);
                    int kBit = inS ? 0 : v;
                    int new_tk;
                    if (tk) {
                        if (kBit < mBit)      new_tk = 0;
                        else if (kBit > mBit) continue;
                        else                  new_tk = 1;
                    } else {
                        new_tk = 0;
                    }
                    ndp[new_tc][new_tk] += dp[tc][tk];
                }
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }
    
    return dp[0][0] + dp[0][1] + dp[1][0] + dp[1][1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        long long x1, x2;
        cin >> x1 >> x2;
        
        long long bestS = 0;
        long long bestCount = countPairs(0, x2);
        
        for (long long S = 1; S < x1; S++) {
            if (S >= x2) {
                bestS = S;
                bestCount = 0;
                break;
            }
            long long c = countPairs(S, x2);
            if (c < bestCount) {
                bestCount = c;
                bestS = S;
            }
        }
        
        cout << 1 << " " << (x1 - bestS) << "\n";
    }
    
    return 0;
}