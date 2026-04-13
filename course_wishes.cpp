#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[25];
int b[55];
vector<int> ops;

bool moveUp(int i) {
    int cur = b[i];
    if (cur == k + 1) return false; 
    int nxt = cur + 1;
    
    if (nxt == k + 1) {
        b[i]++;
        ops.push_back(i);
        return true;
    }
    
    int cnt = 0;
    for (int j = 1; j <= n; j++)
        if (b[j] == nxt) cnt++;
    
    if (cnt < a[nxt - 1]) {
        b[i]++;
        ops.push_back(i);
        return true;
    }

    for (int j = 1; j <= n; j++) {
        if (j != i && b[j] == nxt) {
            if (moveUp(j)) {
                b[i]++;
                ops.push_back(i);
                return true;
            }
        }
    }
    
    return false; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= k; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        ops.clear();
        
        bool possible = true;
        int maxOps = n * k + 10;
        while (true) {
            bool done = true;
            for (int i = 1; i <= n; i++) {
                if (b[i] != k + 1) { done = false; break; }
            }
            if (done) break;
            
            bool progress = false;
            for (int i = 1; i <= n; i++) {
                if (b[i] != k + 1) {
                    if (moveUp(i)) progress = true;
                }
            }
            if (!progress) { possible = false; break; }
        }
        
        if (!possible) {
            cout << -1 << "\n";
        } else {
            cout << ops.size() << "\n";
            for (int x : ops) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}