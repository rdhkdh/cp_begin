// source: USACO guide
// https://usaco.guide/problems/cses-1133-tree-distances-ii/solution

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
vector<int> graph[200001];
ll dp[200001], ans[200001]; // dp= size of each subtree, ans= sum of distances from the node to all other nodes.

void dfs1(int node = 1, int parent = 0, ll depth = 0)
{
    ans[1] += depth;
    dp[node] = 1;
    for (int i : graph[node])
        if (i != parent)
        {
            dfs1(i, node, depth + 1);
            dp[node] += dp[i];
        }
}

void dfs2(int node = 1, int parent = 0)
{
    for (int i : graph[node])
        if (i != parent)
        {
            ans[i] = ans[node] + n - 2 * dp[i];
            dfs2(i, node);
        }
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs1();
    dfs2();
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}