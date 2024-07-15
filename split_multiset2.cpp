#include <bits/stdc++.h>
using namespace std;

int min_operations_to_ones(int n, int k) {
    if (n == 1) return 0;
    if (n <= k) return 1;

    int operations = 0;
    
    if (n % k != 0) {
        // If n is not divisible by k, reduce it by the remainder
        operations++; //split qk and r
        int r = n%k;
        if(r!=1) {operations++;} //split r

        operations += min_operations_to_ones(n-r,k);
    } 
    else 
    {
        // If n is divisible by k, split it into k parts of q
        operations++; //split into k parts of q, or q parts of k (if q<=k)
        int q = (n/k);

        if(q<=k)
        {
            operations += min(k*min_operations_to_ones(q,k), q); //split each of the q's
        }
        else{
            operations += (k*min_operations_to_ones(q,k)); //split each of the q's
        }
        
    }
    
    
    return operations;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << min_operations_to_ones(n, k) << endl;
    }
    return 0;
}
