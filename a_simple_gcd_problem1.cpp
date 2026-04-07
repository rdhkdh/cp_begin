#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long gL = (i > 0) ? __gcd(a[i-1], a[i]) : 1;
            long long gR = (i < n-1) ? __gcd(a[i], a[i+1]) : 1;
            long long L = gL / __gcd(gL, gR) * gR; // lcm(gL, gR)
            if (L < a[i]) ans++;
        }
        
        cout << ans << "\n";
    }
    return 0;
}