#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << (a + b + c + min({a, b, c})) / 3 << "\n";
    }
    return 0;
}