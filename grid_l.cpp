#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        long long p, q;
        cin >> p >> q;
        long long S = p + 2LL * q;
        long long val = 2LL * S + 1LL;

        long long A = -1;
        for (long long i = 3; i * i <= val; i += 2)
        {
            if (val % i == 0)
            {
                A = i;
            }
        }

        A = -1;
        for (long long i = 3; i * i <= val; i += 2)
        {
            if (val % i == 0)
            {
                A = i;
            }
        }

        if (A == -1)
        {
            cout << -1 << "\n";
            continue;
        }

        long long B = val / A;
        long long n = (A - 1) / 2;
        long long m = (B - 1) / 2;
        if (p >= m - n)
        {
            cout << n << " " << m << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}