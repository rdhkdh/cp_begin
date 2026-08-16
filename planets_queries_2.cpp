/*
 * Functional graphs and binary lifting:
 *
 * 1. Graph Structure:
 *    Each component consists of exactly one directed cycle with directed trees 
 *    flowing into it.
 *    - Cycle nodes: depth = 0, labeled with cycle_id, pos (0..L-1), and cycle_len L.
 *    - Tree nodes: depth = number of steps to reach the cycle.
 *
 * 2. Query (a -> b):
 *    - Case 1 (b is NOT on a cycle):
 *      b is reachable iff it is an ancestor of a in the tree.
 *      Check if depth[a] >= depth[b] and lift(a, depth[a] - depth[b]) == b.
 *      -> Return depth[a] - depth[b] if valid, else -1.
 *
 *    - Case 2 (b IS on a cycle):
 *      Lift a to its cycle root a' = lift(a, depth[a]).
 *      If cycle_id[a'] == cycle_id[b],
 *      -> Return depth[a] + (pos[b] - pos[a'] + L) % L, else -1.

 Time Complexity = O((n+q)logn)
 */


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOGN = 20;

int t[MAXN];
int in_degree[MAXN];
int up[LOGN][MAXN];

int depth[MAXN];
int cycle_id[MAXN];
int pos_in_cycle[MAXN];
int cycle_len[MAXN];
bool in_cycle[MAXN];

// Lift node x by k steps
int lift(int x, int k) {
    for (int j = 0; j < LOGN; j++) {
        if ((k >> j) & 1) {
            x = up[j][x];
        }
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        in_degree[t[i]]++;
        up[0][i] = t[i];
    }

    // 1. Binary lifting table
    for (int j = 1; j < LOGN; j++) {
        for (int i = 1; i <= n; i++) {
            up[j][i] = up[j - 1][up[j - 1][i]];
        }
    }

    // 2. Peel off tree nodes using Kahn's algorithm
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            Q.push(i);
        }
    }

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        int v = t[u];
        in_degree[v]--;
        if (in_degree[v] == 0) {
            Q.push(v);
        }
    }

    // 3. Mark and index cycle nodes
    int current_cycle_id = 1;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] > 0 && !in_cycle[i]) {
            vector<int> cycle;
            int curr = i;
            while (!in_cycle[curr]) {
                in_cycle[curr] = true;
                cycle.push_back(curr);
                curr = t[curr];
            }

            int L = cycle.size();
            for (int p = 0; p < L; p++) {
                int node = cycle[p];
                cycle_id[node] = current_cycle_id;
                pos_in_cycle[node] = p;
                cycle_len[current_cycle_id] = L;
                depth[node] = 0;
            }
            current_cycle_id++;
        }
    }

    // 4. Compute depths for non-cycle nodes (reverse BFS from cycle nodes)
    vector<vector<int>> rev(n + 1);
    queue<int> tree_q;
    for (int i = 1; i <= n; i++) {
        rev[t[i]].push_back(i);
        if (in_cycle[i]) {
            tree_q.push(i);
        }
    }

    while (!tree_q.empty()) {
        int u = tree_q.front();
        tree_q.pop();

        for (int v : rev[u]) {
            if (!in_cycle[v]) {
                depth[v] = depth[u] + 1;
                cycle_id[v] = cycle_id[u];
                tree_q.push(v);
            }
        }
    }

    // 5. Answer queries
    while (q--) {
        int a, b;
        cin >> a >> b;

        // If b is not in a cycle
        if (!in_cycle[b]) {
            if (depth[a] >= depth[b] && lift(a, depth[a] - depth[b]) == b) {
                cout << depth[a] - depth[b] << "\n";
            } else {
                cout << -1 << "\n";
            }
        } 
        // If b is in a cycle
        else {
            int a_cycle_root = lift(a, depth[a]);
            if (cycle_id[a_cycle_root] == cycle_id[b]) {
                int L = cycle_len[cycle_id[b]];
                int dist_on_cycle = (pos_in_cycle[b] - pos_in_cycle[a_cycle_root] + L) % L;
                cout << depth[a] + dist_on_cycle << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}