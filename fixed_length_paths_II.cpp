// USACO: https://usaco.guide/problems/cses-2081-fixed-length-paths-ii/solution
// CF: https://codeforces.com/blog/entry/79048

#include <bits/stdc++.h>
using namespace std;
#define SZ 200005
#define ll long long

vector<int> adj[SZ];
int n, k1, k2;
long long ans;

int suf(deque<int> &suf, int idx)
{
    if (idx < 0)
        return suf[0];
    if (idx > suf.size() - 1)
        return 0;
    return suf[idx];
}

/* suf[i] -> sum of nodes having depth in range [i, inf) */

void mergeSuffixes(deque<int> &sa, deque<int> &sb)
{
    if (sa.size() < sb.size())
        swap(sa, sb);
    for (int i = 0; i < sb.size(); i++)
        ans += 1LL * (suf(sb, i) - suf(sb, i + 1)) * (suf(sa, k1 - i) - suf(sa, k2 - i + 1));
    for (int i = 0; i < sb.size(); i++)
        sa[i] += sb[i];
}

deque<int> dfs(int u, int p)
{
    deque<int> suf_parent{1};
    for (int v : adj[u])
    {
        if (v != p)
        {
            deque<int> suf_child = dfs(v, u);
            suf_child.push_front(suf_child.front()); // bcoz depth of child[0] should correspond to parent[1]
            mergeSuffixes(suf_parent, suf_child);
        }
    }
    return suf_parent;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k1 >> k2;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cout << ans;
    return 0;
}