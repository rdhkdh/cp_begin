#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        long long g = a[0];
        for (int i = 1; i < n; i++) g = __gcd(g, a[i]);

        // Find smallest x >= 2 that is coprime with g
        long long ans = -1;
        
        for (long long x = 2; x <= 10; x++) 
        { // small check
            if (__gcd(x, g) == 1) {
                ans = x;
                break;
            }
        }
        if (ans == -1) ans = g + 1; // guaranteed coprime
        if (ans > 1e18) ans = -1;

        cout << ans << "\n";
    }


    return 0;
}