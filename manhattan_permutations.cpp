#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> find_permutation(int n, int k) {
    // Start with the identity permutation
    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1;
    }
    
    int current_value = 0;

    // Create displacements
    int i = n;
    while (k > 0 && i > 0) {
        int max_displacement = i - 1;  // maximum possible displacement for the current element
        
        if (current_value + max_displacement <= k) {
            // Place the element in its maximum displaced position
            swap(permutation[i-1], permutation[n-i]);
            current_value += max_displacement;
        } else {
            // Displace the element just enough to reach k
            int swap_with = i - 1 - (k - current_value);
            swap(permutation[i-1], permutation[swap_with]);
            current_value = k;
        }
        i--;
    }

    if (current_value != k) {
        return {-1};  // not possible to achieve exactly k
    }
    return permutation;
}

int main() {
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    vector<int> result = find_permutation(n, k);

    if (result.size() == 1 && result[0] == -1) {
        cout << "No permutation with Manhattan value " << k << " exists." << endl;
    } else {
        cout << "Permutation with Manhattan value " << k << ": ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
