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
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

void update(vector<int> &a, vector<int> &tree, int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        a[idx] += val;
        tree[node] += val;
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
        tree[node] = tree[2*node]+tree[2*node+1];
    }
}

int query(vector<int> &a, vector<int> &tree, int node, int start, int end, int l, int r)
{
    if (start > r || end < l) // completely outside
    {
        return 0;
    } 
    if (l <= start && end <= r) // completely inside
    {
        return tree[node];
    } 

    // partially inside
    int mid = (start + end) / 2;
    int p1 = query(a, tree, 2 * node, start, mid, l, r);
    int p2 = query(a, tree, 2 * node + 1, mid + 1, end, l, r);
    return (p1+p2);
}

int32_t main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    //we make a difference array for this type of ques
    vector<int> d(n+1);
    d[1] = a[1];
    for(int i=2;i<=n;i++)
    {
        d[i] = a[i]-a[i-1];
    }

    vector<int> tree(4 * n); // 1 -> 2*n-1 nodes, but use extra space for safety

    build(d,tree,1,1,n);

    int x,y,u,k,num;
    for (int i = 1; i <= q; i++)
    {
        cin>>num;
        if(num==2) //query an index
        {
            cin>>k;
            cout<<query(d, tree, 1, 1, n, 1, k)<<endl;
        }
        else if(num==1) //update a range
        {
            cin>>x>>y>>u;
            update(d,tree,1,1,n,x,u); //add u to position x of diff array
            if(y+1<=n) {update(d,tree,1,1,n,y+1,-u);} //subtract u from posn y+1 of diff array
        }
        
        
    }
}