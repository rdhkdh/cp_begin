#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 200000 + 5;

long long fact[MAXN], invfact[MAXN];

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

vector<int> g[MAXN];
int n, k;
long long ans;

int dfs(int u, int p) {
    int sz = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        int s = dfs(v, u);
        long long add = nCr(s, k);
        long long add2 = nCr(n - s, k);
        ans = (ans - add - add2 + 2LL * MOD) % MOD;
        sz += s;
    }
    return sz;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
    invfact[MAXN - 1] = modpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        ans = (1LL * n * nCr(n, k)) % MOD;
        dfs(1, 0);
        cout << ans % MOD << "\n";
    }
    return 0;
}
