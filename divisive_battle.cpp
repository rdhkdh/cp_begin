#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& v : a) cin >> v;
        
        // Check if already non-decreasing → Bob wins immediately
        bool sorted = true;
        for (int i = 0; i+1 < n; i++)
            if (a[i] > a[i+1]) { sorted = false; break; }
        if (sorted) { cout << "Bob\n"; continue; }
        
        auto factorize = [](int x) {
            vector<int> ps;
            for (int i = 2; (long long)i*i <= x; i++)
                while (x % i == 0) { ps.push_back(i); x /= i; }
            if (x > 1) ps.push_back(x);
            return ps;
        };
        
        long long T = 0;
        bool hasMoves = false;
        for (int v : a) {
            if (v <= 1) continue;
            auto ps = factorize(v);
            T += (int)ps.size() - 1;
            if ((int)ps.size() >= 2) hasMoves = true;
        }
        
        // No moves and not sorted → Alice wins
        if (!hasMoves) { cout << "Alice\n"; continue; }
        
        // Odd total splits → Alice makes last move, can maintain unsorted
        if (T % 2 == 1) { cout << "Alice\n"; continue; }
        
        // Even total splits → Bob makes last move
        // Bob wins iff prime factor blocks are globally non-decreasing
        // (meaning the fully expanded array is inevitably sorted)
        bool bobWins = true;
        int prevMax = 0;
        for (int v : a) {
            int minP, maxP;
            if (v == 1) {
                minP = maxP = 1;
            } else {
                auto ps = factorize(v);
                minP = ps.front(); // smallest prime factor
                maxP = ps.back();  // largest prime factor
            }
            if (prevMax > minP) { bobWins = false; break; }
            prevMax = maxP;
        }
        
        cout << (bobWins ? "Bob" : "Alice") << "\n";
    }
}
