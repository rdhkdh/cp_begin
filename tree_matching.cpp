#include<bits/stdc++.h>
using namespace std;
#define NIL 0
#define INF (1<<28)

const int SZ = 400005;
int  u, v;
vector<int> adj_inp[SZ];
vector<int> adj[SZ];
int n, match[SZ], dist[SZ];
 
bool bfs() {
    int i;
    queue<int> Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            for(int v: adj[u]) {
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}
 
bool dfs(int u) {
    if(u!=NIL) {
        for(int v: adj[u]) {
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}
 
int hopcroft_karp_max_match() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in adj
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}
 
void make_bipartite_dfs(int u, int p, int l) {
    if(l%2 and p != -1) {
        adj[u].push_back(p+n);
        adj[p+n].push_back(u);
    }
    for(int v: adj_inp[u]) {
        if(v!=p) {
            if(l%2) {
                adj[u].push_back(v+n);
                adj[v+n].push_back(u);
            }
            make_bipartite_dfs(v, u, l+1);
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        adj_inp[u].push_back(v);
        adj_inp[v].push_back(u);
    }
    make_bipartite_dfs(1, -1, 1);
    cout << hopcroft_karp_max_match() << endl;
}