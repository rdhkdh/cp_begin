#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,k;
    cin>>t;
    

    while(t--)
    {
        cin>>n>>k;
        string s[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }

        
        int q = n/k;
        //char ans[q][q];

        for(int i=0;i<=q-1;i++)
        {
            for(int j=0;j<=q-1;j++)
            {
                //ans[i][j] = s[i*k][j*k];
                cout<<s[i*k][j*k];
            }
            cout<<endl;
        }

        //for(int i=0;i<n;i++)

    }
}