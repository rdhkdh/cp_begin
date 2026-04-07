#include <bits/stdc++.h>
using namespace std;

bool solve(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop(); // match this pair
        } else {
            st.push(c);
        }
    }
    return st.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << (solve(s) ? "YES" : "NO") << "\n";
    }
    return 0;
}