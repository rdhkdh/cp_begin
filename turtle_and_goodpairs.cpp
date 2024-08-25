#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void maximizeGoodPairs(int t, vector<string>& test_cases) {
    for(int i = 0; i < t; ++i) {
        string s = test_cases[i];
        sort(s.begin(), s.end());
        cout << s << endl;
    }
}

int main() {
    int t;
    cin >> t;
    vector<string> test_cases(t);
    for(int i = 0; i < t; ++i) 
    {
        int n;
        cin >> n;
        cin >> test_cases[i];
    }
    
    maximizeGoodPairs(t, test_cases);
    return 0;
}
