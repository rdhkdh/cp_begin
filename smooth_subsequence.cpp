#include <bits/stdc++.h>
using namespace std;

int longest_subseq(int n, int k, vector<int>& nums) {
    vector<int> dp(n, 0);
    vector<int> max_length(1001, 0); // Assuming integers are within the range [0, 1000]

    for (int i = 0; i < n; i++) {
        int curr = nums[i];
        int lower = max(0, curr - k);
        int upper = min(1000, curr + k);

        for (int j = lower; j <= upper; j++) {
            dp[i] = max(dp[i], max_length[j] + 1);
        }
        max_length[curr] = max(dp[i], max_length[curr]);
    }

    int ans = 0;
    for (int i : dp) ans = max(i, ans);

    return ans;
}

int main() {
    vector<int> nums;
    int d,n,x;
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        nums.push_back(x);
    }

    cout << longest_subseq(n, d, nums) << endl;
    return 0;
}
