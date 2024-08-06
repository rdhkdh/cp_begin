#include <bits/stdc++.h>
using namespace std;

// Function to calculate nCr (combinations)
long long comb(int n, int r) {
    if (r > n) return 0;
    if (r > n - r) r = n - r;  // Take advantage of symmetry nCr == nC(n-r)
    long long res = 1;
    for (int i = 0; i < r; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

// Function to find the sum of medians of all subsequences of length k
long long sumOfMedians(int n, int k, const vector<int>& a) {
    int half_k = k / 2;
    long long sum_medians = 0;

    // Iterate over each element in the array
    for (int i = 0; i < n; ++i) {
        // Check if the element can be a median
        if (i >= half_k && n - i - 1 >= half_k) {
            // Calculate combinations of selecting half_k elements before and after
            long long left_ways = comb(i, half_k);
            long long right_ways = comb(n - i - 1, half_k);
            
            // Contribution of a[i] being the median
            long long count_as_median = left_ways * right_ways;
            sum_medians += a[i] * count_as_median;
        }
    }

    return sum_medians;
}

int main() 
{
    int t;
    cin>>t;

    int n,k;

    while(t--)
    {
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) {cin>>a[i];}

        long long result = sumOfMedians(n, k, a);
        cout<<result<<endl;
    }

}
