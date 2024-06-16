#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        char a[n];
        int count[7] = {0,0,0,0,0,0,0};
        for(int i=0;i<n;i++)
        {
            cin>>a[i];

            switch(a[i])
            {
                case 'A': count[0]++; break;
                case 'B': count[1]++; break;
                case 'C': count[2]++; break;
                case 'D': count[3]++; break;
                case 'E': count[4]++; break;
                case 'F': count[5]++; break;
                case 'G': count[6]++; break;
            }
        }

        int ans=0;
        for(int i=0;i<7;i++)
        {
            ans += max(0,m-count[i]);
        }

        cout<<ans<<endl;
        
    }
    

    return 0;
}