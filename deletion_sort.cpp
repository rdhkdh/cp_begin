#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<int> s = a;
        sort(s.begin(), s.end());

        if(a==s) {cout<<n<<endl;}
        else{cout<<1<<endl;}
    }
}