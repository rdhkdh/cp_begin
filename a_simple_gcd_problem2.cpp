#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return a + b; // lcm(x,0) = x, lcm(0,y) = y
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        vector<long long> pref(n + 2, 0), suff(n + 2, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = gcd(pref[i - 1], a[i - 1]);
        }
        for (int i = n; i >= 1; i--) {
            suff[i] = gcd(suff[i + 1], a[i - 1]);
        }
        
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            long long L = pref[i - 1];
            long long R = suff[i + 1];
            
            long long gL = gcd(L, a[i - 1]);
            long long gR = gcd(a[i - 1], R);
            
            long long d = lcm(gL, gR);
            if (d == 0) d = max(gL, gR); // Handle zero case
            
            long long max_k = b[i - 1] / d;
            if (max_k == 0) continue;
            
            // Get the restrictions: k must be coprime to avoid
            long long Lp = (L == 0 || L < d) ? 1 : L / d;
            long long Rp = (R == 0 || R < d) ? 1 : R / d;
            long long avoid = lcm(Lp, Rp);
            
            long long target_k = -1;
            if (a[i - 1] % d == 0) {
                target_k = a[i - 1] / d;
            }
            
            bool can = false;
            
            // Check small values
            for (long long k = 1; k <= min(max_k, 200LL); k++) {
                if (k != target_k && gcd(avoid, k) == 1) {
                    can = true;
                    break;
                }
            }
            
            // Also check max_k and nearby values if max_k is large
            if (!can && max_k > 200) {
                for (long long k = max_k; k >= max_k - 100 && k >= 1; k--) {
                    if (k != target_k && gcd(avoid, k) == 1) {
                        can = true;
                        break;
                    }
                }
            }
            
            if (can) ans++;
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}