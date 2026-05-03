#include <bits/stdc++.h>
using namespace std;

// Check if X (a k-digit number) has smallest period exactly k,
// i.e., X is NOT itself a repeated block of any smaller divisor of k.
bool isAperiodic(long long X, int k) {
    string s = to_string(X);
    // s should have exactly k characters (caller ensures this).
    for (int p = 1; p < k; p++) {
        if (k % p != 0) continue;  // period must divide length
        bool periodic = true;
        for (int i = p; i < k; i++) {
            if (s[i] != s[i % p]) { periodic = false; break; }
        }
        if (periodic) return false;  // found a smaller period
    }
    return true;
}

int main() {
    string input = "61-71,12004923-12218173,907895-1086340,61083-74975,"
                   "7676687127-7676868552,3328-4003,48-59,3826934-3859467,"
                   "178-235,75491066-75643554,92-115,1487-1860,483139-586979,"
                   "553489051-553589200,645895-722188,47720238-47818286,"
                   "152157-192571,9797877401-9798014942,9326-11828,"
                   "879837-904029,4347588-4499393,17-30,1-16,109218-145341,"
                   "45794-60133,491-643,2155-2882,7576546102-7576769724,"
                   "4104-5014,34-46,67594702-67751934,8541532888-8541668837,"
                   "72-87,346340-480731,3358258808-3358456067,78265-98021,"
                   "7969-9161,19293-27371,5143721-5316417,5641-7190,"
                   "28793-36935,3232255123-3232366239,706-847,204915-242531,"
                   "851-1135,790317-858666";

    // Parse ranges
    vector<pair<long long, long long>> ranges;
    stringstream ss(input);
    string token;
    while (getline(ss, token, ',')) {
        auto dash = token.find('-');
        long long lo = stoll(token.substr(0, dash));
        long long hi = stoll(token.substr(dash + 1));
        ranges.push_back({lo, hi});
    }

    // Find the overall max so we know how big k*r can get.
    long long globalMax = 0;
    for (auto [lo, hi] : ranges) globalMax = max(globalMax, hi);
    int maxDigits = to_string(globalMax).size();

    long long total = 0;

    // Loop over (k, r): block length k, repeated r times, total length = k*r.
    for (int k = 1; k * 2 <= maxDigits; k++) {
        // Precompute 10^k
        long long powK = 1;
        for (int i = 0; i < k; i++) powK *= 10;

        long long xLow  = (k == 1) ? 1 : powK / 10;  // smallest k-digit number
        long long xHigh = powK - 1;                   // largest k-digit number

        for (int r = 2; k * r <= maxDigits; r++) {
            // Multiplier M(k, r) = 1 + 10^k + 10^(2k) + ... + 10^((r-1)k)
            long long M = 0, pw = 1;
            bool overflow = false;
            for (int i = 0; i < r; i++) {
                M += pw;
                if (i < r - 1) {
                    // Check overflow before multiplying
                    if (pw > (long long)2e18 / powK) { overflow = true; break; }
                    pw *= powK;
                }
            }
            if (overflow) break;

            for (auto [lo, hi] : ranges) {
                // Solve lo <= X * M <= hi
                long long xMin = max(xLow,  (lo + M - 1) / M);
                long long xMax = min(xHigh, hi / M);
                if (xMin > xMax) continue;

                // Sum X * M over aperiodic X in [xMin, xMax].
                // For small k, iterating X is fine. For k=1, every X is aperiodic.
                if (k == 1) {
                    long long n = xMax - xMin + 1;
                    long long sumX = (xMin + xMax) * n / 2;
                    total += M * sumX;
                } else {
                    for (long long X = xMin; X <= xMax; X++) {
                        if (isAperiodic(X, k)) {
                            total += X * M;
                        }
                    }
                }
            }
        }
    }

    cout << total << endl;
    return 0;
}