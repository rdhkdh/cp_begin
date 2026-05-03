#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    long long sum = 0; // 12-digit numbers, need long long
    const int K = 12;

    while (getline(cin, s))
    {
        int n = s.length();
        string result = "";
        int pos = 0;

        for (int i = 0; i < K; i++)
        {
            // Search window: must leave enough chars for remaining picks
            int window_end = n - (K - i - 1); // exclusive

            char best = '0';
            int best_pos = pos;
            for (int j = pos; j < window_end; j++)
            {
                if (s[j] >= best)
                { // >= to pick latest occurrence on ties
                    best = s[j];
                    best_pos = j;
                }
            }

            result += best;
            pos = best_pos + 1;
        }

        sum += stoll(result);
    }

    cout << sum << endl;
}