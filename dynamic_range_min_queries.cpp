#include <bits/stdc++.h>
using namespace std;
#define int long long

void build(vector<int> &a, vector<int> &tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(a, tree, 2 * node, start, mid);
        build(a, tree, 2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

void update(vector<int> &a, vector<int> &tree, int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        a[idx] = val;
        tree[node] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if (idx >= start && idx <= mid)
        {
            update(a, tree, 2 * node, start, mid, idx, val);
        }
        else
        {
            update(a, tree, 2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

int query(vector<int> &a, vector<int> &tree, int node, int start, int end, int l, int r)
{
    if (start > r || end < l) // completely outside
    {
        return INT_MAX;
    }
    if (l <= start && end <= r) // completely inside
    {
        return tree[node];
    }

    // partially inside
    int mid = (start + end) / 2;
    int p1 = query(a, tree, 2 * node, start, mid, l, r);
    int p2 = query(a, tree, 2 * node + 1, mid + 1, end, l, r);
    return min(p1, p2);
}

int32_t main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> tree(4 * n); // 1 -> 2*n-1 nodes, but allocate more space than necessary for correct answer

    build(a, tree, 1, 1, n);

    int x, y, num;
    for (int i = 1; i <= q; i++)
    {
        cin >> num >> x >> y;
        if (num == 1)
        {
            update(a, tree, 1, 1, n, x, y);
        }
        else if (num == 2)
        {
            cout << query(a, tree, 1, 1, n, x, y) << endl;
        }
    }
}