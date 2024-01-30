#include <bits/stdc++.h>
using namespace std;

int minCostToReachLast(const std::vector<int>& v) {
    int n = v.size();

    // Initialize a vector to store the minimum cost to reach each element
    std::vector<int> minCost(n, INT_MAX);

    // Base case: The cost to reach the first element is 0
    minCost[0] = 0;

    // Iterate through each element
    for (int i = 1; i < n; ++i) {
        // Consider all possible jumps of size 1, 2, and 3
        for (int j = 1; j <= 3; ++j) {
            // Check if the current jump is within the array bounds
            if (i - j >= 0) {
                // Update the minimum cost to reach the current element
                minCost[i] = std::min(minCost[i], minCost[i - j] + abs(v[i] - v[i - j]));
            }
        }
    }

    // The result is the minimum cost to reach the last element
    return minCost[n - 1];
}

int main() {
    // Example usage
    std::vector<int> v = {30,10,60,10,60};

    // Calculate and print the minimum cost to reach the last element
    std::cout << "Minimum cost to reach the last element: " << minCostToReachLast(v) << std::endl;

    return 0;
}
