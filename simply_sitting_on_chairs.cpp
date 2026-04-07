#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];
        
        vector<int> prefix(n + 2, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i + 1] = prefix[i] + (p[i] <= i ? 1 : 0);
        }
        
        int ans = prefix[n + 1];
        
        for (int i = 1; i <= n; i++) {
            if (p[i] > i) {
                int j = p[i];
                ans = max(ans, prefix[j] + 1);
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}