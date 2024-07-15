#include <bits/stdc++.h>
using namespace std;

// Function to find the positions of bits set in n
vector<int> getSetBitPositions(int n) {
    vector<int> positions;
    for (int i = 0; n > 0; ++i) {
        if (n & 1) {
            positions.push_back(i);
        }
        n >>= 1;
    }
    return positions;
}

// Function to find the longest increasing sequence
vector<int> findLongestIncreasingSequence(int n) {
    vector<int> setBitPositions = getSetBitPositions(n);
    vector<int> sequence;
    int current = 0;

    // Generate sequence by setting bits one by one
    for (int bit : setBitPositions) {
        current |= (1 << bit);
        sequence.push_back(current);
    }
    
    return sequence;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> sequence = findLongestIncreasingSequence(n);

    cout << "Longest increasing sequence: ";
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
