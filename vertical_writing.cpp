#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    vector<string> S(N);
    
    int M = 0;
    for (int i = 0; i < N; ++i) 
    {
        cin >> S[i];
        if (S[i].length() > M) { M = S[i].length(); }
    }

    vector<string> T(M, string(N, '*'));

    for (int i = 0; i < N; ++i) 
    {
        int len = S[i].length();
        for (int j = 0; j < len; ++j) 
        {
            T[j][N - i - 1] = S[i][j];
        }
    }


    for (auto& t : T) 
    {
        t.erase(t.find_last_not_of('*') + 1);
        cout << t << endl;
    }

    return 0;
}
