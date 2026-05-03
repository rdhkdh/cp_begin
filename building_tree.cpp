#include <bits/stdc++.h>
using namespace std;

struct RollbackUF
{
    vector<int> parent, sz;
    vector<vector<int>> blockCC;
    struct HistEntry
    {
        int kind, b, aOldSize, appendCount;
    };
    vector<HistEntry> history;
    int numComponents;

    void init(int n)
    {
        parent.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        blockCC.assign(n + 1, {});
        history.clear();
        numComponents = n;
    }

    int find(int x) const
    {
        while (parent[x] != x)
            x = parent[x];
        return x;
    }

    void rollback()
    {
        auto h = history.back();
        history.pop_back();
        if (h.kind == 0)
            return;
        int b = h.b;
        int a = parent[b];
        sz[a] = h.aOldSize;
        parent[b] = b;
        auto &la = blockCC[a];
        for (int k = 0; k < h.appendCount; k++)
            la.pop_back();
        numComponents++;
    }
};

struct SmallUF
{
    vector<int> parent, rnk;
    int numComponents;
    void init(int n)
    {
        parent.assign(n + 1, 0);
        rnk.assign(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        numComponents = n;
    }
    int find(int x)
    {
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
        numComponents--;
        return true;
    }
};

RollbackUF graphUF;
SmallUF newUF;
long long totalCost;

void uniteWithCost(int aIn, int bIn, int costIfMerge)
{
    int a = graphUF.find(aIn), b = graphUF.find(bIn);
    if (a == b)
    {
        graphUF.history.push_back({0, 0, 0, 0});
        return;
    }
    if (graphUF.sz[a] < graphUF.sz[b])
        swap(a, b);
    int oldSizeA = graphUF.sz[a];

    auto &listA = graphUF.blockCC[a];
    auto &listB = graphUF.blockCC[b];

    int anchor = listA.empty() ? -1 : newUF.find(listA[0]);
    int appendCount = 0;
    for (int cc : listB)
    {
        if (anchor == -1)
        {
            anchor = newUF.find(cc);
        }
        else
        {
            int rcc = newUF.find(cc);
            if (rcc != anchor && newUF.unite(rcc, anchor))
            {
                totalCost += costIfMerge;
                anchor = newUF.find(anchor);
            }
        }
        listA.push_back(cc);
        appendCount++;
    }

    graphUF.parent[b] = a;
    graphUF.sz[a] += graphUF.sz[b];
    graphUF.history.push_back({1, b, oldSizeA, appendCount});
    graphUF.numComponents--;
}

int LIM;
vector<vector<pair<int, int>>> segEdges;

void segAdd(int node, int l, int r, int ql, int qr, int u, int v)
{
    if (qr < l || r < ql)
        return;
    if (ql <= l && r <= qr)
    {
        segEdges[node].push_back({u, v});
        return;
    }
    int mid = (l + r) >> 1;
    segAdd(node * 2, l, mid, ql, qr, u, v);
    segAdd(node * 2 + 1, mid + 1, r, ql, qr, u, v);
}

void segDfs(int node, int l, int r)
{
    int added = 0;
    for (auto &e : segEdges[node])
    {
        uniteWithCost(e.first, e.second, l);
        added++;
    }

    if (l != r && newUF.numComponents > 1)
    {
        int mid = (l + r) >> 1;
        segDfs(node * 2, l, mid);
        if (newUF.numComponents > 1)
            segDfs(node * 2 + 1, mid + 1, r);
    }
    while (added--)
        graphUF.rollback();
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> edgeU(m), edgeV(m), edgeW(m);
    vector<int> weightFreq(m + 2, 0);

    for (int i = 0; i < m; i++)
    {
        cin >> edgeU[i] >> edgeV[i] >> edgeW[i];
        if (edgeW[i] <= m + 1)
            weightFreq[edgeW[i]]++;
    }

    vector<int> color(q);
    for (auto &x : color)
        cin >> x;

    int mexWeight = 0;
    while (mexWeight <= m && weightFreq[mexWeight] > 0)
        mexWeight++;

    LIM = mexWeight;
    segEdges.assign(4 * (LIM + 1) + 10, {});

    for (int i = 0; i < m; i++)
    {
        int w = edgeW[i];
        if (w - 1 >= 0)
            segAdd(1, 0, LIM, 0, min(w - 1, LIM), edgeU[i], edgeV[i]);
        if (w + 1 <= LIM)
            segAdd(1, 0, LIM, w + 1, LIM, edgeU[i], edgeV[i]);
    }

    newUF.init(q);
    vector<int> firstByColor(n + 2, -1);
    for (int i = 0; i < q; i++)
    {
        int c = color[i];
        if (firstByColor[c] == -1)
            firstByColor[c] = i;
        else
            newUF.unite(i, firstByColor[c]);
    }

    graphUF.init(n);
    totalCost = 0;
    for (int c = 1; c <= n; c++)
    {
        if (firstByColor[c] != -1)
            graphUF.blockCC[c].push_back(firstByColor[c]);
    }

    segDfs(1, 0, LIM);

    cout << (newUF.numComponents != 1 ? -1 : totalCost) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;
    while (testCases--)
        solve();

    return 0;
}