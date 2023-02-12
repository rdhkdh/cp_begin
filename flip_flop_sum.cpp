#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int sum = 0, flag = 0; //assuming no -1s
        for (int i = 0; i < n; i++)
        {
            if (a[i] == -1)
            {
                flag = 2;
            }
            sum += a[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == -1 && a[i + 1] == -1)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            cout << sum - 4 << endl;
        }
        if (flag == 1)
        {
            cout << sum + 4 << endl;
        }
        if (flag == 2)
        {
            cout << sum << endl;
        }
    }
}