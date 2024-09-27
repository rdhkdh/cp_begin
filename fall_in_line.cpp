#include <bits/stdc++.h>
using namespace std;

// Function to calculate the greatest common divisor (GCD) to normalize slopes
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int t;
    cin >> t;
    int og = t;

    int n;
    while (t--)
    {
        cin >> n;
        if (n < 3)
        {
            cout << 0 << endl;
            continue;
        }

        int x[n], y[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }

        int max_on_line = 0;

        // Loop over each ant as the reference point
        for (int i = 1; i < n; ++i)
        {
            map<pair<int, int>, int> slope_count; // To store the slope frequency
            int duplicates = 1;                   // To count ants at the same point
            int local_max = 0;

            int dx = x[i] - x[0];
            int dy = y[i] - y[0];

            if (dx == 0 && dy == 0) // Ant j is at the same position as ant i
            {
                duplicates++;
            }
            else
            {
                // Normalize the slope (dy/dx) by reducing it to its simplest form
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Make sure the slope is unique (positive dx)
                if (dx < 0)
                {
                    dx = -dx;
                    dy = -dy;
                }

                // Increment the count for this slope
                slope_count[{dx, dy}]++;
                local_max = max(local_max, slope_count[{dx, dy}]);
            }

            // Maximum ants on the same line passing through ants[i]
            max_on_line = max(max_on_line, local_max + duplicates);
        }

        cout << n - max_on_line << endl;
    }
}
