#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int n, m;
        cin >> n >> m;

        int result;
        if (a <= b)
        {
            result = (a * m * (n / (m + 1))) + (n % (m + 1)) * a;
        }
        if (a > b)
        {
            int x = a * m / (m + 1);
            if (x > b)
            {
                result = n * b;
            }
            if (x <= b)
            {
                result = (a * m * (n / (m + 1))) + (n % (m + 1)) * b;
            }
        }
        cout << result << endl;
    }
}