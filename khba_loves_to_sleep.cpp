#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    long long x;
    cin >> n >> k >> x;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    // If k == 1, we need to find the position that minimizes the maximum distance
    if (k == 1) {
        // Find the position that gives the smallest maximum distance
        long long best_pos = 0;
        long long min_max_dist = x * 2;
        
        // Try candidate positions: 0, x, and all friend positions
        vector<long long> candidates = {0LL, x};
        for (long long pos : a) {
            candidates.push_back(pos);
        }
        
        for (long long candidate : candidates) {
            if (candidate < 0 || candidate > x) continue;
            
            long long max_dist = 0;
            for (long long friend_pos : a) {
                long long dist = abs(friend_pos - candidate);
                max_dist = max(max_dist, dist);
            }
            
            if (max_dist < min_max_dist) {
                min_max_dist = max_dist;
                best_pos = candidate;
            }
        }
        
        cout << best_pos << "\n";
        return;
    }
    
    // For k > 1, we need to cover the range optimally
    // Strategy: Place teleports at strategic positions to cover friends
    
    if (k >= n) {
        // We have enough teleports for all friends - place at all friend positions
        // and fill remaining with any distinct positions
        set<long long> teleports;
        for (long long pos : a) {
            teleports.insert(pos);
        }
        
        // Add more positions if needed
        for (long long pos = 0; pos <= x && teleports.size() < k; pos++) {
            teleports.insert(pos);
        }
        
        for (long long pos : teleports) {
            cout << pos << " ";
        }
        cout << "\n";
        return;
    }
    
    // General case: k > 1 and k < n
    // We want to maximize the minimum distance to nearest teleport
    // This is equivalent to minimizing the maximum gap coverage
    
    // Calculate gaps between sorted friends
    vector<pair<long long, int>> gaps;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) {
            gaps.push_back({a[i] - a[i-1], i});
        }
    }
    
    // Sort gaps by size (largest first since we want to cover the biggest gaps)
    sort(gaps.rbegin(), gaps.rend());
    
    // We'll place teleports to cover the largest gaps
    set<long long> teleports;
    
    // Always include endpoints 0 and x if beneficial
    teleports.insert(0);
    teleports.insert(x);
    
    // Add friend positions as potential teleport locations
    for (long long pos : a) {
        teleports.insert(pos);
    }
    
    // Focus on covering the largest gaps
    for (int i = 0; i < min((int)gaps.size(), k - 2); i++) {
        int idx = gaps[i].second;
        long long gap_start = a[idx - 1];
        long long gap_end = a[idx];
        
        // Place teleports in the middle of large gaps
        long long mid = (gap_start + gap_end) / 2;
        teleports.insert(mid);
        
        // Also add positions near the middle to cover the gap well
        if (mid > 0) teleports.insert(mid - 1);
        if (mid < x) teleports.insert(mid + 1);
    }
    
    // If we still need more teleports, add strategic positions
    while (teleports.size() < k) {
        // Find the position that would best improve coverage
        long long best_pos = -1;
        long long best_improvement = -1;
        
        // Try positions at regular intervals
        for (long long pos = 0; pos <= x; pos += max(1LL, x / (k * 2))) {
            if (teleports.count(pos)) continue;
            
            // Calculate the improvement this position would provide
            long long min_dist_to_friend = x * 2;
            for (long long friend_pos : a) {
                min_dist_to_friend = min(min_dist_to_friend, abs(friend_pos - pos));
            }
            
            if (min_dist_to_friend > best_improvement) {
                best_improvement = min_dist_to_friend;
                best_pos = pos;
            }
        }
        
        if (best_pos != -1) {
            teleports.insert(best_pos);
        } else {
            // Just add any available position
            for (long long pos = 0; pos <= x; pos++) {
                if (!teleports.count(pos)) {
                    teleports.insert(pos);
                    break;
                }
            }
        }
    }
    
    // Output the teleports
    for (long long pos : teleports) {
        cout << pos << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}