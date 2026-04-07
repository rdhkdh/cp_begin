#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<int> a(n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        
        if(n <= 2){ printf("0\n"); continue; }
        
        int LOG = __lg(n) + 1;
        vector<vector<int>> sp(LOG, vector<int>(n));
        for(int i = 0; i < n; i++) sp[0][i] = i;
        for(int j = 1; j < LOG; j++)
            for(int i = 0; i + (1<<j) <= n; i++){
                int l = sp[j-1][i], r = sp[j-1][i+(1<<(j-1))];
                sp[j][i] = (a[l] >= a[r]) ? l : r;
            }
        
        auto qmax_pos = [&](int l, int r) -> int {
            if(l > r) return -1;
            int k = __lg(r - l + 1);
            int L = sp[k][l], R = sp[k][r-(1<<k)+1];
            return (a[L] >= a[R]) ? L : R;
        };
        
        struct Node { int l, r, p, lc, rc, ans; };
        vector<Node> nodes;
        nodes.reserve(n);
        
        auto make_node = [&](int l, int r) -> int {
            if(l > r) return -1;
            int p = qmax_pos(l, r);
            int id = nodes.size();
            nodes.push_back({l, r, p, -1, -1, 0});
            return id;
        };
        
        int root = make_node(0, n-1);
        queue<int> q;
        q.push(root);
        while(!q.empty()){
            int id = q.front(); q.pop();
            auto& nd = nodes[id];
            if(nd.l < nd.p){ nd.lc = make_node(nd.l, nd.p-1); if(nd.lc>=0) q.push(nd.lc); }
            if(nd.p < nd.r){ nd.rc = make_node(nd.p+1, nd.r); if(nd.rc>=0) q.push(nd.rc); }
        }
        
        for(int i = (int)nodes.size()-1; i >= 0; i--){
            auto& nd = nodes[i];
            if(nd.r - nd.l + 1 <= 2){ nd.ans = 0; continue; }
            int la = nd.lc >= 0 ? nodes[nd.lc].ans : 0;
            int ra = nd.rc >= 0 ? nodes[nd.rc].ans : 0;
            nd.ans = min(nd.p - nd.l + ra, nd.r - nd.p + la);
        }
        
        printf("%d\n", nodes[root].ans);
    }
}