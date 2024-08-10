#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int xc, yc, k;
        cin >> xc >> yc >> k;

        int x[k], y[k];
        
        int sum_x = xc * k;
        int sum_y = yc * k;

        // Place the first point at the center point * k
        x[0] = sum_x - (k - 1); 
        y[0] = sum_y - (k - 1);
        
        for (int i = 1; i < k; i++) {
            x[i] = x[i - 1] + 1;
            y[i] = y[i - 1] + 1;
        }

        // Adjust the remaining k - 1 points
        for (int i = 1; i < k; i += 2) {
            x[i] -= (2 * i);
            y[i] -= (2 * i);
        }

        for (int i = 0; i < k; i++) {
            cout << x[i] << " " << y[i] << endl;
        }
    }

    return 0;
}
