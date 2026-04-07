#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long k = 1;
        long long temp = n;
        for (long long p = 2; p * p <= temp; p++) {
            if (temp % p == 0) {
                k *= p;
                while (temp % p == 0) temp /= p;
            }
        }
        if (temp > 1) k *= temp;
        cout << k << "\n";
    }
}