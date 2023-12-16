#include <bits/stdc++.h>
using namespace std;

// djikstra's algo
vector<long long> min_costs(int src, const vector<vector<pair<int, int>>> &neighbors)
{
    vector<long long> min_costs(neighbors.size(), INT64_MAX);
    min_costs[src] = 0;

    priority_queue<pair<long long, int>> pq; //cost,point
    pq.push({0, src});
    while (!pq.empty())
    {
        pair<long long, int> current = pq.top();
        pq.pop();
        int u = current.second;
        if (-current.first != min_costs[u])
        {
            continue;
        }

        for (auto [v,w] : neighbors[u])
        {
            long long new_cost = min_costs[u] + w;
            if (new_cost < min_costs[v])
            {
                min_costs[v] = new_cost;
                pq.push({-new_cost, v});
            }
        }
    }
    return min_costs;
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> neighbors(n);
    vector<vector<pair<int, int>>> reverse_neighbors(n);
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        neighbors[--a].push_back({--b, c});
        reverse_neighbors[b].push_back({a, c});
    }

    vector<long long> start_costs = min_costs(0, neighbors);
    vector<long long> end_costs = min_costs(n - 1, reverse_neighbors);

    long long total_min = INT64_MAX;
    for (int i = 0; i < n; i++)
    {
        for (auto [v,w] : neighbors[i])
        {
            if (start_costs[i] == INT64_MAX || end_costs[v] == INT64_MAX)
            {
                continue;
            }
            total_min = min(total_min, start_costs[i] + (w / 2) + end_costs[v]);
        }
    }
    cout << total_min << endl;
}