// Fenwick tree, O(logn), point update and range queries
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define SZ 200005

int n, m, k, x, q, s;
int timer;
int start[SZ];
int endd[SZ];
int value[SZ];
int bit[SZ];
vector<int> adj[SZ];

void update(int i, int delta)
{
    for (; i <= n; i += i & -i)
        bit[i] += delta;
}

int query(int i)
{
    int sum = 0;
    for (; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}

void dfs(int u, int p)
{
    start[u] = ++timer;
    update(timer, value[u]);

    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }
    endd[u] = timer;
}

signed main()
{
    int type;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> s >> x;
            update(start[s], -value[s]);
            value[s] = x;
            update(start[s], +value[s]);
        }
        else
        {
            cin >> s;
            cout << query(endd[s]) - query(start[s] - 1) << "\n";
        }
    }
}