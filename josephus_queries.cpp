#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k) 
{
    if (n == 1) return 1;
    
    // If removed in the first complete sweep (including wrap-around for odd n)
    if (k <= (n + 1) / 2) 
    {
        if (2 * k > n) return 1; // wrap-around for odd n
        return 2 * k;
    }
    
    // Recurse on the remaining floor(n/2) children
    int ans = solve(n / 2, k - (n + 1) / 2);
    return (n % 2 == 1) ? (2 * ans + 1) : (2 * ans - 1);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (cin >> q) 
    {
        while (q--) 
        {
            long long n, k;
            cin >> n >> k;
            cout << solve(n, k) << "\n";
        }
    }
    return 0;
}