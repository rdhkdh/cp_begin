#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,q;
    cin>>t;

    while(t--)
    {
        cin>>n>>q;
        string a,b;

        cin>>a;
        cin>>b;

        int query[q][2];
        for(int i=0;i<q;i++)
        {
            cin>>query[i][0]>>query[i][1];
        }

        int freq_a[26][n+1];
        int freq_b[26][n+1];

        for(int i=0;i<26;i++)
        {
            for(int j=0;j<=n;j++)
            {
                freq_a[i][j] = 0;
                freq_b[i][j] = 0;
            }
        }

        freq_a[a[0]-int('a')][0] = 0; //1-based indexing
        freq_b[b[0]-int('a')][0] = 0;

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<26;j++)
            {
                freq_a[j][i] = freq_a[j][i-1];
                freq_b[j][i] = freq_b[j][i-1];
            }


            freq_a[a[i-1]-int('a')][i] = freq_a[a[i-1]-int('a')][i-1] + 1; //1-based
            freq_b[b[i-1]-int('a')][i] = freq_b[b[i-1]-int('a')][i-1] + 1;
        }

        for(int i=0;i<q;i++)
        {
            int l = query[i][0]; 
            int r = query[i][1];

            int f_curr_a[26] = {0};
            int f_curr_b[26] = {0};

            int count=0;
            for(int i=0;i<26;i++)
            {
                f_curr_a[i] = freq_a[i][r] - freq_a[i][l-1]; //1-based
                f_curr_b[i] = freq_b[i][r] - freq_b[i][l-1]; 

                count += abs(f_curr_a[i] - f_curr_b[i]);
            }
            cout<<count/2<<endl;

        }
    }
}