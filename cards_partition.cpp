#include <bits/stdc++.h>
using namespace std;

bool canMakeDeckSize(int sum, int k, int d)
{
    if(sum%d <= k) {return true;}
    return false;
}

int maxDeckSize(int sum, int n, int k)
{
    // Binary search on the possible deck size
    int low = 1, high = n, result = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canMakeDeckSize(sum, k, mid))
        {
            result = mid; // mid is a valid deck size, try larger sizes
            low = mid + 1;
        }
        else
        {
            high = mid - 1; // mid is too large, try smaller sizes
        }
    }

    return result;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int sum=0;
        for (int i = 0; i < n; ++i) 
        { 
            cin >> a[i]; 
            sum += a[i];
        } 

        cout << maxDeckSize(sum, n, k) << endl;
    }
    

    

    return 0;
}
