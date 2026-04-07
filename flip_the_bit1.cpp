#include <bits/stdc++.h>
using namespace std;

int count_segments(vector<int>& a, int l, int r, int x) {
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (a[i] != x) {
            cnt++;
            while (i <= r && a[i] != x) i++; // skip segment
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k; // k = 1

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int p;
        cin >> p;
        p--; // convert to 0-based

        int x = a[p];

        int left_segments = count_segments(a, 0, p - 1, x);
        int right_segments = count_segments(a, p + 1, n - 1, x);

        cout << 2*max(left_segments, right_segments) << "\n";
    }

    return 0;
}