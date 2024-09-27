#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("line_of_delivery_part_1_input.txt","r",stdin);
    freopen("line_of_delivery_part_1_output.txt","w",stdout);

    int t;
    cin>>t;
    int og=t;

    int n,g;

    while(t--)
    {
        cin>>n>>g;
        vector<int> e(n);
        for(int i=0;i<n;i++) {cin>>e[i];}

        sort(e.rbegin(),e.rend()); //descending order

        int min_distance = INT_MAX, closest_stone=-1;
        for (int i = 0; i < n; ++i) 
        {
            int distance = abs(e[i] - g);
            if (distance < min_distance) {
                min_distance = distance;
                closest_stone = i + 1;  // 1-based stone index
            }
        }

        cout << "Case #" << og-t << ": " << closest_stone <<" "<< min_distance << endl;
    }
}