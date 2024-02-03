#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;

    while (t--)
    {
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int i = 0, j = 1;
        
        for(i=0;i<n;i++)
        {
            j=i+1;
            while (i < j && j < n)
            {
                if (a[j] < a[i] && b[j] < b[i])
                {
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                    j++;
                }
                else
                {
                    j++;
                }
            }
        }
        
        

        for (auto u : a)
        {
            cout << u << " ";
        }
        cout << endl;

        for (auto u : b)
        {
            cout << u << " ";
        }
        cout << endl;
    }
}