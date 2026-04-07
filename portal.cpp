#include<bits/stdc++.h>
using namespace std;

vector<int> combine(vector<int> &a,
                    vector<int> &b,
                    vector<int> &c)
{
    vector<int> res;
    res.insert(res.end(), a.begin(), a.end());
    res.insert(res.end(), b.begin(), b.end());
    res.insert(res.end(), c.begin(), c.end());
    return res;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,x,y;
        cin >> n >> x >> y;

        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];

        // correct splitting
        vector<int> part1(v.begin(), v.begin()+x);
        vector<int> part2(v.begin()+x, v.begin()+y);
        vector<int> part3(v.begin()+y, v.end());

        vector<vector<int>> candidates;

        // original permutation
        candidates.push_back(v);

        // -------- OP 1 --------
        if(!part1.empty())
        {
            auto a=part1,b=part2,c=part3;

            int val=a.back();
            a.pop_back();
            c.insert(c.begin(),val);

            candidates.push_back(combine(a,b,c));
        }

        // -------- OP 2 --------
        if(!part2.empty())
        {
            auto a=part1,b=part2,c=part3;

            int val=b.back();
            b.pop_back();
            b.insert(b.begin(),val);

            candidates.push_back(combine(a,b,c));
        }

        // -------- OP 3 --------
        if(!part2.empty())
        {
            auto a=part1,b=part2,c=part3;

            int val=b.front();
            b.erase(b.begin());
            b.push_back(val);

            candidates.push_back(combine(a,b,c));
        }

        // -------- OP 4 --------
        if(!part3.empty())
        {
            auto a=part1,b=part2,c=part3;

            int val=c.front();
            c.erase(c.begin());
            a.push_back(val);

            candidates.push_back(combine(a,b,c));
        }

        // lexicographically smallest
        vector<int> ans =
            *min_element(candidates.begin(),
                         candidates.end());

        for(int x : ans)
            cout << x << " ";
        cout << "\n";
    }
}