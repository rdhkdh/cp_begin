#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n, m, a, b;
        cin >> n >> m >> a >> b;
        
        if (__gcd(n, a) == 1 && __gcd(m, b) == 1 && __gcd(n, m) <= 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}