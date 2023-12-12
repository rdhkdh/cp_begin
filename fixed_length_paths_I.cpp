// centroid decomposition

#include <bits/stdc++.h>
using namespace std;
#define SZ 200005

vector<int> adj[SZ];
int sub[SZ], cnt[SZ], n, k, max_d; // cnt[d] = no of paths of length d edges
long long ans;
bool vis[SZ];

void dfs_sub(int u, int p)
{ // calculating subtree sizes
    sub[u] = 1;
    for (int v : adj[u])
    {
        if (!vis[v] && v != p)
        {
            dfs_sub(v, u);
            sub[u] += sub[v];
        }
    }
}

int find_centroid(int u, int p, int treeSz)
{
    for (int v : adj[u])
    {
        if (!vis[v] && v != p && sub[v] > treeSz)
        {
            return find_centroid(v, u, treeSz);
        }
    }
    return u;
}

void dfs(int u, int p, int d, bool isCalculate)
{
    if (d > k)
        return;
    if (isCalculate)
    {
        ans += cnt[k - d];
    }
    else
    {
        cnt[d]++;
    }
    max_d = max(max_d, d);

    for (int v : adj[u])
    {
        if (!vis[v] && v != p)
        {
            dfs(v, u, d + 1, isCalculate);
        }
    }
}

void centroid_decompose(int u)
{
    dfs_sub(u, -1);
    int centroid = find_centroid(u, -1, sub[u] >> 1);
    vis[centroid] = true;
    cnt[0] = 1;
    max_d = 0;
    for (int v : adj[centroid])
    {
        if (!vis[v])
        {
            dfs(v, centroid, 1, true);
            dfs(v, centroid, 1, false);
        }
    }
    fill(cnt, cnt + max_d + 10, 0);
    for (int v : adj[centroid])
    {
        if (!vis[v])
        {
            centroid_decompose(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    centroid_decompose(1);
    cout << ans;
}