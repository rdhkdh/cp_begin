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

        sort(a.rbegin(),a.rend());

        int largest = a[0];
        int ans=1;

        for(int i=1;i<n;i++)
        {
            if(a[i]==largest)
            {
                ans++;
            }
            else{
                break;
            }
        }

        cout<<ans<<endl;
    }
}