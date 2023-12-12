#include<bits/stdc++.h>
using namespace std;
#define SZ 200005

int n; 
vector<int> adj[SZ];
vector<int> ans(SZ, -1); //max dist to another node
 
int bfs(int src) //return the farthest node from src
{
	int top;
	queue<int> q;
	vector<int> d(n+1, -1);
	d[src] = 0;
	ans[src] = max(ans[src], d[src]);
	q.push(src);
 
	while(!q.empty()) {
		top = q.front();
		q.pop();
 
		for(int v: adj[top]) {
			if(d[v] == -1) {
				q.push(v);
				d[v] = d[top] + 1;
				ans[v] = max(ans[v], d[v]);
			}
		}
	}
	return top;
}
 
int main() {
	int u, v;
	
	cin >> n;
	for(int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
    //obtain the 2 ends of diameter
	int diam_end_1 = bfs(1);
	int diam_end_2 = bfs(diam_end_1);
    //run bfs from diam_end 1 and 2 to obtain max dist to another node, for each node in the tree.
	bfs(diam_end_2);
 
	for(int i = 1; i <=n ; i++) {
		cout << ans[i] << " ";
	}
}