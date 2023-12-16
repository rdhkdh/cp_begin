// APSP: Floyd Warshall Algo

#include<bits/stdc++.h>
using namespace std;
const int max_n= 500;
const long long INF = 0x3f3f3f3f3f3f3f3f; //64 bit hex notation

int main()
{
    int n,m,q;
    cin>>n>>m>>q;

    int a,b;
    long long dist[max_n+1][max_n+1];
    long long c;
    memset(dist, 0x3f, sizeof(dist)); //8 bit hex notation
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[b][a],c);
    }

    for(int i=1;i<=n;i++)
    {
        dist[i][i]=0;
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        if(dist[a][b]>=INF) {cout<<"-1\n";}
        else{cout<<dist[a][b]<<endl;}
    }
}