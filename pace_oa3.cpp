#include <bits/stdc++.h>
using namespace std;

int bioHazard(int n, vector<int>& allergic, vector<int>& poisonous) 
{
    vector<int> d(n+1, -1); //-1: not allergic

    // Update dictionary with poisonous relationships
    for (int i = 0; i < allergic.size(); i++) 
    {
        int a = allergic[i];
        int b = poisonous[i];
        if (a > b) swap(a, b);  // Ensure a < b

        d[b] = max(d[b], a);
    }

    // Propagate maximum values in the dictionary
    for (int i = 1; i <= n; i++) {
        d[i] = max(d[i], d[i - 1]);
    }

    // Calculate the number of valid intervals
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == -1) {
            res += i;
        } else {
            res += (i - d[i]);
        }
    }
    
    return res;
}

int main() {
    // Example usage
    int n = 3;
    vector<int> allergic = {2,1,3};
    vector<int> poisonous = {3,3,1};
    
    cout<< bioHazard(n, allergic, poisonous) << endl;
    return 0;
}
