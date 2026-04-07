#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n+2, 0);
        for(int i = 1; i <= n; i++) cin >> a[i];
        vector<int> p(k);
        for(int i = 0; i < k; i++) cin >> p[i];
        
        int x = a[p[0]];
        
        // e[i] = a[i]^x, with e[0]=e[n+1]=0
        // D[i] = e[i]^e[i-1]
        // Segments defined by boundaries: 0, p[0], p[1], ..., p[k-1], n+1
        // Segment s: D-positions (bounds[s], bounds[s+1]]
        
        vector<int> bounds;
        bounds.push_back(0);
        for(int i = 0; i < k; i++) bounds.push_back(p[i]);
        bounds.push_back(n+1);
        
        auto eval = [&](int i) -> int {
            if(i <= 0 || i > n) return 0;
            return a[i] ^ x;
        };
        
        int T = 0, M = 0;
        int ns = (int)bounds.size() - 1; // number of segments
        for(int s = 0; s < ns; s++){
            int lo = bounds[s] + 1;
            int hi = bounds[s+1];
            int cnt = 0;
            for(int i = lo; i <= hi; i++){
                if((eval(i) ^ eval(i-1)) == 1) cnt++;
            }
            T += cnt;
            M = max(M, cnt);
        }
        
        cout << max(T/2, M) << "\n";
    }
    return 0;
}