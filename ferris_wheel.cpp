// two pointer approach

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, y,count=0;
    cin >> n >> x;

    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v, v+n);

    int i=0,j=n-1;
    
    while (i <= j)
    {
        if(i==j) {count++; break;}
        if ((v[i] + v[j]) <= x)
        {
            count++;
            i++;
            j--;
        }
        else{
            count++;
            j--;
        }
    }
    cout<<count;
}