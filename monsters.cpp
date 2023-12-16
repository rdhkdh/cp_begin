#include <bits/stdc++.h>
using namespace std;
#define mn 1005

int N, M;
queue<pair<int, int>> q;
int paths[mn][mn];
pair<int, int> from[mn][mn];
pair<int, int> A;
string ans;
bool possible = false;

void retrace(pair<int, int> node)
{   // retrace from final node, adding direction from
    // previous node to a string. This string will be
    // backwards but will be reversed before output.
    pair<int, int> origin = from[node.first][node.second];
    if (origin == pair<int, int>(0, 0))
        return;
    if (origin.first == node.first + 1)
        ans.push_back('U');
    if (origin.first == node.first - 1)
        ans.push_back('D');
    if (origin.second == node.second + 1)
        ans.push_back('L');
    if (origin.second == node.second - 1)
        ans.push_back('R');
    retrace(origin);
}

void check(pair<int, int> origin, pair<int, int> dest)
{ // check if the considered destination may be traveled to
    int pl = paths[origin.first][origin.second];
    if (pl + 1 < paths[dest.first][dest.second])
    {
        paths[dest.first][dest.second] = pl + 1;
        q.push(dest);
        from[dest.first][dest.second] = origin;
    }
}

bool mora = false; // false if bfs for monsters, true if bfs for A

void bfs()
{
    while (!q.empty())
    {
        pair<int, int> loc = q.front(), next;
        q.pop();
        next = loc;
        next.first++;
        check(loc, next); // go through adjacent locations
        next = loc;
        next.first--;
        check(loc, next);
        next = loc;
        next.second++;
        check(loc, next);
        next = loc;
        next.second--;
        check(loc, next);
        if (mora && (loc.first == 1 || loc.second == 1 || loc.first == N ||
                     loc.second == M))
        {
            cout << "YES" << endl;
            cout << paths[loc.first][loc.second] << endl;
            retrace(loc);
            possible = true;
            return;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++)
        {
            paths[i][j] = INT_MAX;
            if (s[j - 1] == '#')
                paths[i][j] = 0;
            if (s[j - 1] == 'M')
            {
                q.push(pair<int, int>(i, j));
                paths[i][j] = 0;
            }
            if (s[j - 1] == 'A')
            {
                A.first = i;
                A.second = j;
            }
        }
    }

    bfs();       // monster bfs
    mora = true; // change next bfs to A bfs
    from[A.first][A.second] = pair<int, int>(0, 0); // give the retrace a terminating location
    paths[A.first][A.second] = 0;
    q.push(A); // get ready for next bfs
    bfs();     // bfs with A
    
    if (possible)
    {
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    else
    {cout << "NO" << endl;}

    return 0;
}