#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int n, ans[N];
deque<int> d[N];
set<int> tickets;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        tickets.insert(x);
        d[x].push_back(i);
    }
    for (int pos = 1; pos <= 2 * n - 1; pos++)
    {
        auto it = tickets.upper_bound(pos);
        if (it == tickets.begin())
            continue;
        it--;
        int person = d[*it].front();
        d[*it].pop_front();
        ans[person] = pos;
        if (d[*it].empty())
            tickets.erase(it);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

signed main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}