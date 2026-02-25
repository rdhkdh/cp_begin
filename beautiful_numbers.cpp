#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        int n = x.size();
        
        // Compute digit sum
        int S = 0;
        for (char c : x) S += (c - '0');
        
        if (S <= 9) {
            cout << 0 << "\n";
            continue;
        }
        
        // Need to reduce sum to ≤ 9
        int need_reduce = S - 9;
        
        // Each digit: (potential_reduction, index)
        vector<pair<int, int>> potentials;
        for (int i = 0; i < n; i++) {
            int v = x[i] - '0';
            if (i == 0) {
                // First digit: can reduce to 1
                if (v > 1) {
                    potentials.push_back({v - 1, i});
                }
            } else {
                potentials.push_back({v, i});
            }
        }
        
        // Sort by reduction amount descending
        sort(potentials.begin(), potentials.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first > b.first;
        });
        
        int moves = 0;
        int remaining = need_reduce;
        for (auto& p : potentials) {
            if (remaining <= 0) break;
            remaining -= p.first;
            moves++;
        }
        
        cout << moves << "\n";
    }
    return 0;
}