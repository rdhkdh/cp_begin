#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<pair<ll, int>> owned(n);
        for (int i = 0; i < n; i++) {
            cin >> owned[i].first >> owned[i].second;
        }
        
        vector<pair<ll, int>> shop(m);
        for (int i = 0; i < m; i++) {
            cin >> shop[i].first >> shop[i].second;
        }
        
        // Sort owned particles by reactivity
        sort(owned.begin(), owned.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });
        
        // For each possible set size k, find maximum sum using owned particles only
        // We need k particles all with reactivity >= k-1
        vector<ll> bestOwned(n + 2, 0);
        
        // Process from largest k to smallest for efficiency
        priority_queue<ll, vector<ll>, greater<ll>> pq; // min-heap to keep top k energies
        ll sum = 0;
        int idx = n - 1;
        
        for (int k = n; k >= 1; k--) {
            // Add particles with reactivity >= k-1
            while (idx >= 0 && owned[idx].second >= k - 1) {
                pq.push(owned[idx].first);
                sum += owned[idx].first;
                idx--;
            }
            
            // Remove smallest if we have more than k
            while (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == k) {
                bestOwned[k] = sum;
            }
        }
        
        // For each shop particle, compute answer
        vector<ll> ans(m);
        
        for (int i = 0; i < m; i++) {
            ll x = shop[i].first;
            int y = shop[i].second;
            
            // Option 1: Don't use shop particle
            ll result = 0;
            for (int k = 1; k <= n; k++) {
                result = max(result, bestOwned[k]);
            }
            
            // Option 2: Use shop particle
            // Try all possible set sizes that include this particle
            for (int k = 1; k <= n + 1; k++) {
                // Shop particle can be in set of size k only if y >= k-1
                if (y < k - 1) continue;
                
                // Need k-1 other particles with reactivity >= k-1
                int needed = k - 1;
                if (needed > n) continue;
                
                if (needed == 0) {
                    result = max(result, x);
                    continue;
                }
                
                // Find best k-1 owned particles with reactivity >= k-1
                // We can reuse our precomputation
                // But we need to ensure we don't double count if x is already in the best set
                
                // Collect eligible owned particles (reactivity >= k-1)
                vector<ll> eligible;
                for (auto& p : owned) {
                    if (p.second >= k - 1) {
                        eligible.push_back(p.first);
                    }
                }
                
                // Sort descending
                sort(eligible.begin(), eligible.end(), greater<ll>());
                
                if (eligible.size() >= needed) {
                    ll sum = x;
                    for (int j = 0; j < needed; j++) {
                        sum += eligible[j];
                    }
                    result = max(result, sum);
                }
            }
            
            ans[i] = result;
        }
        
        // Output
        for (int i = 0; i < m; i++) {
            cout << ans[i] << (i < m - 1 ? " " : "\n");
        }
    }
    
    return 0;
}