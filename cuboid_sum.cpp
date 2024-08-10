#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n][n][n];
    int presum[n][n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            presum[i][j][0] = A[i][j][0];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                presum[i][j][k] = 
            }
        }
    }
}