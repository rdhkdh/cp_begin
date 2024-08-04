#include<bits/stdc++.h>
using namespace std;
#define int long long

int findXorSum(int arr[], int n)
{
    int sum = 0;
    int mul = 1;
 
    for (int i = 0; i < 30; i++) 
    {
        int c_odd = 0;
        bool odd = 0;
 
        for (int j = 0; j < n; j++) 
        {
            if ((arr[j] & (1 << i)) > 0)
                odd = (!odd);
            if (odd)
                c_odd++;
        }

        for (int j = 0; j < n; j++) 
        {
            sum += (mul * c_odd);
 
            if ((arr[j] & (1 << i)) > 0)
                c_odd = (n - j - c_odd);
        }
 
        mul *= 2;
    }

    int s1=0;
    for(int i=0;i<n;i++)
    {
        s1 += arr[i];
    }
 
    return sum-s1;
}


int32_t main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<findXorSum(a,n)<<endl;
}