#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> p(n);
        for(int i = 0; i < n; i++) cin >> p[i];
        
        // B = middle segment (between portals), R = ring (A + C)
        vector<int> B(p.begin() + x, p.begin() + y);
        vector<int> R;
        R.insert(R.end(), p.begin(), p.begin() + x);      // A
        R.insert(R.end(), p.begin() + y, p.end());         // C
        int m = R.size(), q = B.size();
        
        // Find lex smallest rotation of B using Booth's algorithm
        vector<int> Bstar;
        if(q > 0){
            vector<int> bb(B.begin(), B.end());
            bb.insert(bb.end(), B.begin(), B.end());
            vector<int> f(2*q, -1);
            int k = 0;
            for(int j = 1; j < 2*q; j++){
                int i = f[j - 1 - k];
                while(i != -1 && bb[j] != bb[k + i + 1]){
                    if(bb[j] < bb[k + i + 1]) k = j - i - 1;
                    i = f[i];
                }
                if(i == -1 && bb[j] != bb[k + i + 1]){
                    if(bb[j] < bb[k + i + 1]) k = j;
                    f[j - k] = -1;
                } else {
                    f[j - k] = i + 1;
                }
            }
            for(int i = 0; i < q; i++)
                Bstar.push_back(B[(k + i) % q]);
        }
        
        // Find optimal split: include R[k] before B* while R[k] < B*[0]
        int b0 = q > 0 ? Bstar[0] : INT_MAX;
        int split = 0;
        while(split < m && R[split] < b0) split++;
        
        // Output: R[0..split-1] + B* + R[split..m-1]
        for(int i = 0; i < split; i++) cout << R[i] << ' ';
        for(int i = 0; i < q; i++) cout << Bstar[i] << ' ';
        for(int i = split; i < m; i++) cout << R[i] << " \n"[i==m-1 && q==0];
        cout << '\n';
    }
    return 0;
}