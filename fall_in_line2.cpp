#include <bits/stdc++.h>
using namespace std;

// Function to calculate the greatest common divisor (GCD) to normalize slopes
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to find the minimum number of ants to move
int minAntsToMove(vector<pair<int, int>>& ants) 
{
    int N = ants.size();
    if (N < 3) {
        // If there are less than 3 ants, they're already on the same line
        return 0;
    }

    int max_on_line = 0;

    // Loop over each ant as the reference point
    for (int i = 0; i < N; ++i) {
        map<pair<int, int>, int> slope_count;  // To store the slope frequency
        int duplicates = 1;  // To count ants at the same point
        int local_max = 0;

        // Compare the i-th ant with all other ants
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;

            int dx = ants[j].first - ants[i].first;
            int dy = ants[j].second - ants[i].second;

            if (dx == 0 && dy == 0) {
                // Ant j is at the same position as ant i
                duplicates++;
            } else {
                // Normalize the slope (dy/dx) by reducing it to its simplest form
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Make sure the slope is unique (positive dx)
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                // Increment the count for this slope
                slope_count[{dx, dy}]++;
                local_max = max(local_max, slope_count[{dx, dy}]);
            }
        }

        // Maximum ants on the same line passing through ants[i]
        max_on_line = max(max_on_line, local_max + duplicates);
    }

    // Return the minimum number of ants to move
    return N - max_on_line;
}

int main() 
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> ants;

        int x,y;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;

        }
    }

    int N;
    cout << "Enter the number of ants: ";
    cin >> N;

    vector<pair<int, int>> ants(N);

    cout << "Enter the coordinates of the ants (X, Y):" << endl;
    for (int i = 0; i <<
}