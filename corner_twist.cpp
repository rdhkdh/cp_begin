#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    int n,m;
    string s;
    while(t--)
    {
        cin>>n>>m;
        int a[n][m];
        int b[n][m];
        
        
        for(int i=0;i<n;i++)
        {
            cin>>s;
            for(int j=0;j<m;j++)
            {
                a[i][j] = s[j];
            }
        }

        for(int i=0;i<n;i++)
        {
            cin>>s;
            for(int j=0;j<m;j++)
            {
                b[i][j] = s[j];
            }
        }

        //compare row-wise sums remainders mod 3
        int flag=0;
        int a_row_sum=0, b_row_sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                a_row_sum += a[i][j];
                a_row_sum %= 3;

                b_row_sum += b[i][j];
                b_row_sum %= 3;
            }
            if(a_row_sum!=b_row_sum)
            {
                flag=1;
                break;
            }
        }

        if(flag==1) {cout<<"NO\n"; continue;}

        //compare col-wise sums remainders mod 3
        int a_col_sum=0, b_col_sum=0;
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                a_col_sum += a[i][j];
                a_col_sum %= 3;

                b_col_sum += b[i][j];
                b_col_sum %= 3;
            }
            if(a_col_sum!=b_col_sum)
            {
                flag=1;
                break;
            }
        }

        if(flag==1) {cout<<"NO\n";}

        if(flag==0) {cout<<"YES\n";}
    }
}