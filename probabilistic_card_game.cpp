#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long power(long long a, long long b, long long mod) {
    a %= mod; long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long inv(long long a) { return power(a % MOD, MOD - 2, MOD); }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    vector<long long> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    // Coordinate compression
    vector<long long> sorted_vals = a;
    sort(sorted_vals.begin(), sorted_vals.end());
    int M = m;
    auto compress = [&](long long v) -> int {
        return (int)(lower_bound(sorted_vals.begin(), sorted_vals.end(), v) - sorted_vals.begin()) + 1;
    };

    // Fenwick trees (1-indexed)
    vector<long long> fen_cnt(M + 1, 0), fen_sum(M + 1, 0);
    auto update = [&](vector<long long>& fen, int i, long long d) {
        for (; i <= M; i += i & (-i)) fen[i] += d;
    };
    auto query = [&](vector<long long>& fen, int i) -> long long {
        long long s = 0; for (; i > 0; i -= i & (-i)) s += fen[i]; return s;
    };

    // Find k-th smallest (1-indexed) via binary lifting
    int logM = 0;
    while ((1 << (logM + 1)) <= M) logM++;
    auto kth = [&](int k) -> int {
        int pos = 0;
        for (int pw = (1 << logM); pw > 0; pw >>= 1)
            if (pos + pw <= M && fen_cnt[pos + pw] < k) { pos += pw; k -= (int)fen_cnt[pos]; }
        return pos + 1;
    };

    long long totalSum = 0;
    int n = 0;

    // L[j] = sum_{k<j}(v[j]-v[k]), R[j] = sum_{k>j}(v[k]-v[j])
    // L is strictly increasing, R is strictly decreasing.
    // Answer = min_i max(L[i-1], R[i+1]) / (n-2)
    auto getLR = [&](int j) -> pair<long long, long long> {
        int pos = kth(j + 1);
        long long v = sorted_vals[pos - 1];
        long long cnt = j + 1;
        long long sm = query(fen_sum, pos);
        long long L = cnt * v - sm;
        long long R = (totalSum - sm) - (long long)(n - cnt) * v;
        return {L, R};
    };

    for (int round = 0; round < m; round++) {
        long long val = a[round];
        int pos = compress(val);
        update(fen_cnt, pos, 1);
        update(fen_sum, pos, val);
        totalSum += val;
        n++;

        if (n < 3) continue;

        // Binary search for crossing: smallest i where L[i-1] >= R[i+1]
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            long long Lv = (mid > 0) ? getLR(mid - 1).first : (long long)-1e18;
            long long Rv = (mid < n - 1) ? getLR(mid + 1).second : (long long)-1e18;
            if (Lv >= Rv) hi = mid; else lo = mid + 1;
        }

        long long ans = LLONG_MAX;
        for (int i = max(0, lo - 1); i <= min(n - 1, lo + 1); i++) {
            long long Lv = (i > 0) ? getLR(i - 1).first : -1;
            long long Rv = (i < n - 1) ? getLR(i + 1).second : -1;
            long long mx = (i == 0) ? Rv : (i == n - 1) ? Lv : max(Lv, Rv);
            if (mx >= 0) ans = min(ans, mx);
        }

        long long num = ans % MOD;
        long long den = inv(n - 2);
        cout << (num % MOD * den % MOD + MOD) % MOD << "\n";
    }
    return 0;
}