#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<long long> a(n+1), S(n+1, 0);
        for(int i = 1; i <= n; i++) 
        {
            cin>>a[i];
        }
        
        for(int k = 2; k <= n; k++) 
        {
            S[k] = S[k-1] + a[k-1];
        }
        
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 1);
        
        sort(idx.begin(), idx.end(), [&](int x, int y){
            return S[x] > S[y];
        });
        
        vector<int> p(n+1);
        for(int i = 0; i < n; i++) p[idx[i]] = i + 1;
        
        for(int i = 1; i <= n; i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}