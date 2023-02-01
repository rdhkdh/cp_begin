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

        int first_row[n];
        for(int i=1;i<=n-1;i++)
        {
            cin>>first_row[i];
        }

        int diff[n], temp[n];
        int prev=first_row[1];
        for (int i = 2; i <= n; i++)
        {
            for(int j=1;j<=n-1;j++) {cin>>temp[j];}
            int first = temp[1];

            if(first!=prev)
            {
                for(int j=1;j<=n-1;j++) {diff[j]=temp[j];}
                break;
            }
            prev=first;
        }
    }
}