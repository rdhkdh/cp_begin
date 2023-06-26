#include<bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &A) {
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    int size= A.size();
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + A[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}