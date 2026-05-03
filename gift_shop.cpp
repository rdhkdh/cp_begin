#include <bits/stdc++.h>
using namespace std;

int main() {
    // Paste your input string here, or read from stdin.
    string input;
    getline(cin, input);

    // Parse "lo-hi,lo-hi,..." into a vector of pairs.
    vector<pair<long long, long long>> ranges;
    stringstream ss(input);
    string token;
    while (getline(ss, token, ',')) {
        auto dash = token.find('-');
        long long lo = stoll(token.substr(0, dash));
        long long hi = stoll(token.substr(dash + 1));
        ranges.push_back({lo, hi});
    }

    // For each block-length k, every "doubled" number has the form
    // N = X * (10^k + 1), where X has exactly k digits.
    // For each range [lo, hi], find which X values land inside it.
    long long total = 0;
    for (int k = 1; k <= 6; k++) {  // k up to 6 covers numbers up to ~12 digits
        long long mult = 1;
        for (int i = 0; i < k; i++) mult *= 10;  // mult = 10^k
        long long factor = mult + 1;             // 10^k + 1
        long long xLow  = mult / 10;             // smallest k-digit number
        long long xHigh = mult - 1;              // largest k-digit number
        if (k == 1) xLow = 1;                    // 1-digit starts at 1, not 0

        for (auto [lo, hi] : ranges) {
            // Solve lo <= X * factor <= hi for X.
            long long xMin = max(xLow,  (lo + factor - 1) / factor);  // ceil(lo/factor)
            long long xMax = min(xHigh, hi / factor);                 // floor(hi/factor)
            if (xMin > xMax) continue;

            // Sum of X * factor for X in [xMin, xMax]
            // = factor * (sum of X from xMin to xMax)
            long long n = xMax - xMin + 1;
            long long sumX = (xMin + xMax) * n / 2;
            total += factor * sumX;
        }
    }

    cout << total << endl;
    return 0;
}