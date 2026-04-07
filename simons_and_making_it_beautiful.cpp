#include <bits/stdc++.h>
using namespace std;

int countUgly(vector<int>& a) {
    int n = a.size(), cur_max = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        cur_max = max(cur_max, a[i]);
        if (a[i] == cur_max) cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (auto& x : p) cin >> x;
        
        vector<int> best = p;
        int bestCount = countUgly(p);
        
        // Try all possible swaps
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                swap(p[i], p[j]);
                int cnt = countUgly(p);
                if (cnt < bestCount) {
                    bestCount = cnt;
                    best = p;
                }
                swap(p[i], p[j]); // restore
            }
        }
        
        for (int i = 0; i < n; i++) cout << best[i] << " \n"[i==n-1];
    }
    return 0;
}