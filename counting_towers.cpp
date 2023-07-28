#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long mod = 1e9+7;
    int N = 1e6+10;

    long long one_block[N], two_blocks[N]; //to remove segmentation fault here, 
    // use value of n passed in test case
    one_block[1]=1;
    two_blocks[1]=1;

    for(int i=2;i<N;i++)
    {
        one_block[i] = (2 * one_block[i - 1] + two_blocks[i - 1]) % mod;
        two_blocks[i] = (4 * two_blocks[i - 1] + one_block[i - 1]) % mod;
    }

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<< (one_block[n]+two_blocks[n]) %mod <<endl;
    }

    return 0;
}