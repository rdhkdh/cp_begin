// small to large technique
// aliter: Mo's algorithm

#include <bits/stdc++.h>
using namespace std;
#define SZ 200005

int n, m, k, u, v;
vector<int> adj[SZ];
int ans[SZ];
int col[SZ];

set<int> dfs(int u, int p)
{
    set<int> uniq;
    uniq.insert(col[u]);

    for (int v : adj[u])
    {
        if (v != p)
        {
            set<int> child = dfs(v, u);
            if (child.size() > uniq.size())
                swap(child, uniq);
            for (int color : child)
            {
                uniq.insert(color);
            }
        }
    }
    ans[u] = uniq.size();
    return uniq;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> col[i];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}