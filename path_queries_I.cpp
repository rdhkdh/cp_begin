#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 200005;

struct node
{
    int l, r, mx;
    node *left, *right;
    node(int ll, int rr) : l(ll), r(rr), mx(0), left(NULL), right(NULL) {}
} *root[N];

vector<int> chain[N];
vector<int> adj[N];

int sz[N], H[N], P[N], chainHd[N], pos[N], leadingEdge[N];

void update(node *p, int idx, int val)
{
    if (p->l == p->r)
    {
        p->mx = val;
        return;
    }
    int mid = (p->l + p->r) >> 1;
    update(idx <= mid ? p->left : p->right, idx, val);
    p->mx = (p->left->mx + p->right->mx); //store sum in node
}

int query(node *p, int ql, int qr)
{
    if (qr < p->l or p->r < ql)
        return 0;
    if (ql <= p->l and p->r <= qr)
        return p->mx;
    return query(p->left, ql, qr) + query(p->right, ql, qr);
}

node *build(int n, int l, int r)
{
    node *p = new node(l, r);
    if (l < r)
    {
        int mid = (l + r) >> 1;
        p->left = build(n, l, mid);
        p->right = build(n, mid + 1, r);
    }
    p->mx = (l == r) ? leadingEdge[chain[n][l]] : (p->left->mx + p->right->mx);
    return p;
}

void dfs_build(int n, int p, int h)
{
    P[n] = p;
    H[n] = h;
    sz[n] = 1;
    for (int i = 0; i < adj[n].size(); i++)
    {
        int v = adj[n][i];
        if (v - p)
        {
            dfs_build(v, n, h + 1);
            sz[n] += sz[v];
        }
    }
}

void HLD(int n)
{
    chain[n].push_back(n);
    for (int i = 0; i < chain[n].size(); i++)
    {
        int v = chain[n][i];
        chainHd[v] = n;
        pos[v] = i;
        for (int k = 0; k < adj[v].size(); k++)
        {
            int j = adj[v][k];
            if (j != P[v])
                (sz[j] << 1) >= sz[v] ? chain[n].push_back(j) : HLD(j);
        }
    }
    root[n] = build(n, 0, chain[n].size() - 1);
}

int HLDquery(int u, int v)
{
    int ans = 0;
    while (chainHd[u] != chainHd[v])
    {
        if (H[chainHd[u]] > H[chainHd[v]])
            swap(u, v);
        ans += query(root[chainHd[v]], 0, pos[v]);

        v = P[chainHd[v]];
    }
    if (pos[u] > pos[v])
        swap(u, v);
    ans += query(root[chainHd[u]], pos[u], pos[v]);
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q, n, a, b, c, k, ti, type;

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> leadingEdge[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_build(1, 1, 0);
    HLD(1);

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1) //point update
        {
            cin >> k >> ti;
            update(root[chainHd[k]], pos[k], ti);
        }
        else //range query
        {
            cin >> k;
            cout << HLDquery(1, k) << endl;
        }
    }
}