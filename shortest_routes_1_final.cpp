// djikstra's algo

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e5;

struct Edge
{
    int v;
    ll w; //weight
};
struct Node
{
    int id;
    ll dist;
    friend bool operator<(const Node &a, const Node &b)
    { //operator overload
        return a.dist > b.dist;
    }
};

int N, M, a, b;
ll dist[maxN + 1], c;
vector<Edge> G[maxN + 1];
priority_queue<Node> Q; 

int main()
{
    cin>>N>>M;
    for (int i = 0; i < M; i++)
    {
        cin>>a>>b>>c;
        G[a].push_back({b, c});
    }

    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    Q.push({1, 0});
    while (!Q.empty())
    {
        ll d = Q.top().dist;
        int u = Q.top().id;
        Q.pop();

        if (d > dist[u])
            continue;

        for (Edge e : G[u])
        {
            if (dist[e.v] > d + e.w)
            {
                dist[e.v] = d + e.w;
                Q.push({e.v, d + e.w});
            }
        }
    }

    for (int i = 1; i <= N; i++)
    { printf("%lld ", dist[i]); }

    return 0;
}