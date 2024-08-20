#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 10001;
int dp[MAXN][MAXN][2]; // 3D DP table: indices and turn
vector<int> a, b;

// Function to check if Alice wins with the current indices and turn
bool aliceWins(int i, int j, int turn, int n) {
    if (i == j) {
        // Base case: only one element left
        return a[i] != b[i];
    }

    // Check if result is already computed
    if (dp[i][j][turn] != -1) {
        return dp[i][j][turn];
    }

    if (turn == 0) { // Alice's turn
        // Alice wins if she can make a move that results in a Bob's loss in his next optimal move
        bool chooseLeft = !aliceWins(i + 1, j, 1, n);
        bool chooseRight = !aliceWins(i, j - 1, 1, n);
        dp[i][j][turn] = chooseLeft || chooseRight;
    } else { // Bob's turn
        // Bob wins if he can make a move that results in a tie (x == y)
        bool chooseLeft = !aliceWins(i + 1, j, 0, n);
        bool chooseRight = !aliceWins(i, j - 1, 0, n);
        dp[i][j][turn] = chooseLeft && chooseRight;
    }

    return dp[i][j][turn];
}

int main() 
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin >> n;

        a.resize(n);
        b.resize(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Initialize DP table with -1 (uncomputed)
        memset(dp, -1, sizeof(dp));

        // Determine the winner
        if (aliceWins(0, n - 1, 0, n)) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
    

    return 0;
}
