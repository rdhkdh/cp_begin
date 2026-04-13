#include <bits/stdc++.h>
using namespace std;

int query(vector<int>& indices) {
    cout << "? " << indices.size();
    for (int x : indices) cout << " " << x;
    cout << "\n" << flush;
    int res; cin >> res;
    return res;
}

int queryRange(int l, int r) {
    vector<int> idx;
    for (int i = l; i <= r; i++) idx.push_back(i);
    return query(idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int N = 2 * n + 1;
        
        // Find p3: smallest r where f([1..r]) has wrong parity
        int lo = 1, hi = N;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (queryRange(1, mid) % 2 != mid % 2) hi = mid;
            else lo = mid + 1;
        }
        int p3 = lo;
        
        // Find p1: largest l where f([l..N]) has wrong parity
        lo = 1; hi = N;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (queryRange(mid, N) % 2 != (N - mid + 1) % 2) lo = mid;
            else hi = mid - 1;
        }
        int p1 = lo;
        
        // Find p2: smallest m in [p1..p3-1] where f([p1..m] ∪ {p3}) has wrong parity
        lo = p1; hi = p3 - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            vector<int> idx;
            for (int i = p1; i <= mid; i++) idx.push_back(i);
            idx.push_back(p3);
            if (query(idx) % 2 != (mid - p1 + 2) % 2) hi = mid;
            else lo = mid + 1;
        }
        int p2 = lo;
        
        cout << "! " << p1 << " " << p2 << " " << p3 << "\n" << flush;
    }
}