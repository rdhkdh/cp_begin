#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int sum = 0;

    while (getline(cin, s))
    {
        int max_num = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int d1 = s[i] - '0';
                int d2 = s[j] - '0';
                max_num = max(max_num, d1 * 10 + d2);
            }
        }

        sum += max_num;
    }

    cout << sum << endl;
}