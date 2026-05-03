#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n;
vector<int> adj[MAXN];
long long ans[MAXN];

int sz1[MAXN];
int par1[MAXN];

int sub[MAXN];
bool removed_[MAXN];

int s_c[MAXN];
int mx_arr[MAXN];
int grp[MAXN];
int grp_size[MAXN];
int Hcount[MAXN];
int Gcount[MAXN+1];

vector<int> distinct_sigmas;
bool sigma_seen[MAXN+1];

void initSizes1(int root) {
    static int stk[MAXN];
    static int it[MAXN];
    int top = 0;
    stk[top] = root;
    par1[root] = 0;
    it[top] = 0;
    sz1[root] = 1;
    while (top >= 0) {
        int u = stk[top];
        if (it[top] < (int)adj[u].size()) {
            int v = adj[u][it[top]++];
            if (v != par1[u]) {
                par1[v] = u;
                sz1[v] = 1;
                top++;
                stk[top] = v;
                it[top] = 0;
            }
        } else {
            top--;
            if (top >= 0) sz1[stk[top]] += sz1[u];
        }
    }
}

int getSize(int root) {
    static int stk[MAXN];
    static int par[MAXN];
    static int it[MAXN];
    int top = 0;
    stk[top] = root;
    par[root] = -1;
    it[top] = 0;
    sub[root] = 1;
    while (top >= 0) {
        int u = stk[top];
        if (it[top] < (int)adj[u].size()) {
            int v = adj[u][it[top]++];
            if (v != par[u] && !removed_[v]) {
                par[v] = u;
                sub[v] = 1;
                top++;
                stk[top] = v;
                it[top] = 0;
            }
        } else {
            top--;
            if (top >= 0) sub[stk[top]] += sub[u];
        }
    }
    return sub[root];
}

int getCentroid(int root, int tree_size) {
    int u = root, p = -1;
    while (true) {
        bool moved = false;
        for (int v : adj[u]) {
            if (v == p || removed_[v]) continue;
            if (sub[v] > tree_size / 2) {
                p = u;
                u = v;
                moved = true;
                break;
            }
        }
        if (!moved) return u;
    }
}

vector<int> verts_in_Vc;

struct Frame {
    int y, p, group_idx;
    int s_y, M;
    int it;
};

void dfsCompute(int start, int c, int group_idx, int n_total) {
    static Frame stk[MAXN];
    int top = 0;
    int s_start;
    if (c == par1[start]) {
        s_start = sz1[start];
    } else {
        s_start = n_total - sz1[c];
    }
    s_c[start] = s_start;
    grp[start] = group_idx;
    int M_start = 0;
    mx_arr[start] = max(M_start, s_start);
    verts_in_Vc.push_back(start);
    
    stk[top] = {start, c, group_idx, s_start, M_start, 0};
    
    while (top >= 0) {
        Frame &f = stk[top];
        int y = f.y;
        if (f.it < (int)adj[y].size()) {
            int z = adj[y][f.it++];
            if (z == f.p || removed_[z]) continue;
            int s_z;
            if (y == par1[z]) {
                s_z = sz1[z];
            } else {
                s_z = n_total - sz1[y];
            }
            s_c[z] = s_z;
            grp[z] = f.group_idx;
            int newM = max(f.M, f.s_y - s_z);
            mx_arr[z] = max(newM, s_z);
            verts_in_Vc.push_back(z);
            top++;
            stk[top] = {z, y, f.group_idx, s_z, newM, 0};
        } else {
            top--;
        }
    }
}

void solve_centroid(int c, int n_total) {
    verts_in_Vc.clear();
    s_c[c] = n_total;
    
    int D = 0;
    for (int v : adj[c]) {
        if (removed_[v]) continue;
        int s_v;
        if (c == par1[v]) {
            s_v = sz1[v];
        } else {
            s_v = n_total - sz1[c];
        }
        grp_size[D] = s_v;
        dfsCompute(v, c, D, n_total);
        D++;
    }
    
  
    for (int v : verts_in_Vc) {
        int g = grp[v];
        int sigma_g = grp_size[g];
        int val = max(mx_arr[v], n_total - sigma_g);
        ans[val]++;
    }
    

    sort(verts_in_Vc.begin(), verts_in_Vc.end(), [](int a, int b){
        if (mx_arr[a] != mx_arr[b]) return mx_arr[a] < mx_arr[b];
        return a < b;
    });
    
    distinct_sigmas.clear();
    
    for (int y : verts_in_Vc) {
        int g_y = grp[y];
        int sigma_y = grp_size[g_y];
        int M = mx_arr[y];
        
        for (int sigma : distinct_sigmas) {
            int cnt = Gcount[sigma];
            if (sigma == sigma_y) {
                cnt -= Hcount[g_y];
            }
            if (cnt <= 0) continue;
            int val = max(M, n_total - sigma_y - sigma);
            ans[val] += cnt;
        }
        
        if (!sigma_seen[sigma_y]) {
            sigma_seen[sigma_y] = true;
            distinct_sigmas.push_back(sigma_y);
        }
        Gcount[sigma_y]++;
        Hcount[g_y]++;
    }
    
    for (int sigma : distinct_sigmas) {
        Gcount[sigma] = 0;
        sigma_seen[sigma] = false;
    }
    distinct_sigmas.clear();
    for (int g = 0; g < D; g++) {
        Hcount[g] = 0;
    }
}

void decompose(int start) {
    static int qstk[MAXN*4];
    int top = 0;
    qstk[top++] = start;
    while (top > 0) {
        int u = qstk[--top];
        int tree_size = getSize(u);
        int c = getCentroid(u, tree_size);
        solve_centroid(c, n);
        removed_[c] = true;
        for (int v : adj[c]) if (!removed_[v]) {
            qstk[top++] = v;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            ans[i] = 0;
            removed_[i] = false;
        }
        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        ans[n] += n;
        
        if (n >= 2) {
            initSizes1(1);
            decompose(1);
        }
        
        for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i==n];
    }
    
    return 0;
}