// binary lifting

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOGK = 30; // 2^29 < 10^9 < 2^30

// up[j][x] = planet reached after 2^j jumps from planet x
// up[j][x] = up[j-1][up[j-1][x]]
int up[LOGK][MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;

    // 1. Read base jumps (2^0 = 1 step)
    for(int i=1;i<=n;i++)
    {
        cin>>up[0][i];
    }

    //2. Precompute binary lifting table
    for(int j=1;j<LOGK;j++)
    {
        for(int i=1;i<=n;i++)
        {
            up[j][i] = up[j-1][up[j-1][i]];
        }
    }

    //3. Process queries
    while(q--)
    {
        int x,k;
        cin>>x>>k;

        for(int j=0; j<LOGK; j++)
        {
            if((k>>j) & 1)
            {
                x = up[j][x];
            }
        }
        cout<<x<<"\n";
    }
}