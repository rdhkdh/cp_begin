#include <bits/stdc++.h>
using namespace std;

bool feasible(long long s, long long m, long long n) {
    long long lo = 0, hi = 0;
    for (int j = 0; j < 63; j++) {
        int s_j = (s >> j) & 1;
        int m_j = (m >> j) & 1;

        // total = carry + c_j - s_j, where c_j ∈ [0, n*m_j]
        long long t_lo = lo - s_j;           // min c_j = 0
        long long t_hi = hi + (m_j ? n : 0) - s_j;  // max c_j

        // total must be >= 0
        if (t_hi < 0) return false;
        t_lo = max(t_lo, 0LL);

        // total must be even (pairs carry to next bit)
        if (t_lo % 2 != 0) t_lo++;
        if (t_hi % 2 != 0) t_hi--;
        if (t_lo > t_hi) return false;

        lo = t_lo / 2;
        hi = t_hi / 2;
    }
    return lo == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long s, m;
        cin >> s >> m;

        if (m == 0) {
            cout << -1 << "\n";
            continue;
        }

        // Binary search: minimum n such that feasible(s, m, n)
        long long lo = 1, hi = s, ans = -1;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (feasible(s, m, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}