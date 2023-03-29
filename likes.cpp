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
        int pos = 0, neg = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (x > 0)
            {
                pos++;
            }
            else
            {
                neg++;
            }
        }

        int max[n + 1], min[n + 1];
        for (int i = 1; i <= n; i++)
        {
            if (i <= pos)
            {
                max[i] = i;
            }
            else
            {
                max[i] = max[i - 1] - 1;
            }
        }

        //min[1]=1;
        int i=1;
        while (neg > 0)
        {
            if (i % 2 != 0)
            {
                min[i] = 1;
            }
            if (i % 2 == 0)
            {
                min[i] = 0;
                neg--;
            }
            i++;
        }

        
        for(int j=i;j<=n;j++)
        {
            min[j]=j-i+1;
        }

        for(int j=1;j<=n;j++) {cout<<max[j]<<" ";}
        cout<<endl;
        for(int j=1;j<=n;j++) {cout<<min[j]<<" ";}
        cout<<endl;
    }
}