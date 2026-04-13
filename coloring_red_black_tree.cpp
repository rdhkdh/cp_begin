#include <bits/stdc++.h>
using namespace std;
const double INF = 1e18;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(20);
    
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        
        vector<vector<int>> adj(n+1);
        for(int i = 0; i < n-1; i++){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> rr(n+1, 0), deg(n+1, 0);
        for(int v = 1; v <= n; v++){
            deg[v] = adj[v].size();
            for(int u : adj[v])
                if(s[u-1] == '1') rr[v]++;
        }
        
        vector<double> dp0(n+1, INF), dp1(n+1, INF);
        vector<bool> vis(n+1, false);
        double ans = 0;
        
        function<void(int,int)> dfs = [&](int v, int par){
            vis[v] = true;
            vector<int> ch;
            for(int u : adj[v])
                if(s[u-1] == '0' && u != par) ch.push_back(u);
            for(int c : ch) dfs(c, v);
            
            double base = 0;
            vector<double> deltas;
            for(int c : ch){
                base += dp1[c];
                deltas.push_back(dp0[c] - dp1[c]);
            }
            sort(deltas.begin(), deltas.end());
            int k = ch.size();
            vector<double> psum(k+1, 0);
            for(int i = 0; i < k; i++) psum[i+1] = psum[i] + deltas[i];
            
            for(int j = 0; j <= 1; j++){
                double best = INF;
                for(int ss = 0; ss <= k; ss++){
                    int r = rr[v] + j + ss;
                    if(r == 0) continue;
                    double cc = base + psum[ss];
                    if(cc >= INF/2) continue;
                    best = min(best, (double)deg[v]/r + cc);
                }
                (j == 0 ? dp0[v] : dp1[v]) = best;
            }
        };
        
        for(int v = 1; v <= n; v++){
            if(s[v-1] == '0' && !vis[v] && rr[v] > 0){
                dfs(v, -1);
                ans += dp0[v];
            }
        }
        
        cout << ans << "\n";
    }
}