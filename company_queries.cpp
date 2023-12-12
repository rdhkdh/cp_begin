/* 
Description: 
Introduces the problem of kth ancestor and LCA,
solved using Binary Lifting.
Resources:
USACO, CPH: https://usaco.guide/plat/binary-jump?lang=cpp
CF soln: https://codeforces.com/blog/entry/79048
*/

#include <bits/stdc++.h>
using namespace std;
#define SZ 200005

int n, q, u, v, k;

vector<int> adj[SZ];
int jump[21][SZ];
// set 21 because its greater than log2(2*10^5) which is the
// limit of tree height as given in question

void dfs(int u, int p, int l) // l= depth or level
{
    jump[0][u] = p; // jump[i][u] = 2^i jump from u

    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u, l + 1);
        }
    }
}

void preprocess_LCA() // lowest common ancestor
{
    dfs(1, -1, 0);

    for (int i = 1; 1 << i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            jump[i][j] = jump[i - 1][jump[i - 1][j]]; //DP recurrence: 2^i = 2^(i+1) + 2^(i+1)
        }
    }
}

int main()
{
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    preprocess_LCA();
    while (q--)
    {
        cin >> u >> k;
        int boss = u;
        for (int i = 0; i <= 20; i++)
            if (k & (1 << i))
                boss = jump[i][boss];

        cout << (boss == 0 ? -1 : boss) << endl;
    }
}
