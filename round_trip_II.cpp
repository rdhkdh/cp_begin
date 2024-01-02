#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 1;

int start, finish, p[maxN], vis[maxN];
vector<int> G[maxN];

void dfs(int u)
{
    vis[u] = 1;
    for (int v : G[u])
    {
        if (vis[v] == 0)
        {
            p[v] = u;
            dfs(v);
            if (start)
                return;
        }
        else if (vis[v] == 1)
        {
            finish = u;
            start = v;
            return;
        }
    }
    vis[u] = 2;
}

int main()
{
    int N,M;
    cin >> N >> M;
    int a, b;
    for (int i = 0, a, b; i < M; i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
    }

    for (int i = 1; i <= N && !start; i++)
    {
        if (vis[i] == 0)
            dfs(i);
    }

    if (!start)
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    vector<int> ans;
    ans.push_back(start);
    for (int u = finish; u != start; u = p[u])
    {
        ans.push_back(u);
    }
    ans.push_back(start);
    reverse(ans.begin(), ans.end());

    cout<<ans.size()<<endl;
    for(auto u: ans) { cout<<u<<" "; }

    return 0;
}