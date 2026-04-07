#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int,long long>>> adj(n+1);
    
    for(int i = 0; i < m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<long long> dist(n+1, LLONG_MAX);
    // MAX heap instead of min heap ("Dikjstra" = swapped j and k = swapped heap)
    priority_queue<pair<long long,int>> pq;
    
    dist[1] = 0;
    pq.push({0, 1});
    
    vector<bool> vis(n+1, false);
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [v, w] : adj[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    for(int i = 2; i <= n; i++){
        cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << "\n";
    }
    
    return 0;
}