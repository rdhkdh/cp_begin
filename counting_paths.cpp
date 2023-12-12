#include<bits/stdc++.h>
using namespace std;
#define SZ 200005

int n, m, k, x;
int L[SZ]; //L=level
vector<int> adj[SZ]; 
int jump[21][SZ];
vector<int> prefix(SZ, 0); //no of paths
 
//calculates (parent,level) arrays
void dfs(int u, int p, int l) {
    jump[0][u] = p;
    L[u] = l;
	
	for (int v: adj[u]) 
		if(v != p) 
		dfs(v, u, l+1);
}
 
void preprocess_LCA() {	
	dfs(1, 0, 0);
		
	for (int i = 1; 1<<i <= n ; i++) 
	for (int j = 0; j <= n ; j++)
	jump[i][j] = jump[i-1][jump[i-1][j]];
}
 
int LCA(int p,int q) {
	if(L[p] < L[q])
	swap(p, q);
	
	int diff = L[p] - L[q];
	
	for(int i = 20; i >= 0; i--) 
		if(diff & (1<<i)) 
		p = jump[i][p];
		
	if(p == q) return p;
 
	for (int i = 20; i >= 0; i--) {
		if (jump[i][p] != jump[i][q]) {
			p = jump[i][p];
			q = jump[i][q];
		}
	}
	return jump[0][p];
}
 
void dfs_prefix_sum(int u, int p) {
	for(int v: adj[u]) {
		if(v-p) {
			dfs_prefix_sum(v, u);
			prefix[u] += prefix[v];
		}
	}
}
 
 
int main() 
{
	int u, v;
 
	cin >> n >> m;
 
	for(int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	preprocess_LCA();
	
	while (m--)
	{
		cin >> u >> v;
		prefix[u]++;
		prefix[v]++;
		int lca = LCA(u, v);
		prefix[lca]--;
		prefix[jump[0][lca]]--;
	}
	dfs_prefix_sum(1, 0);
 
	for(int i = 1; i <= n ; i++) 
	cout << prefix[i] << " ";
}