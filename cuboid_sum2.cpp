#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N;
    
    vector<vector<vector<int>>> A(N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));
    vector<vector<vector<int>>> P(N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));

    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            for (int z = 1; z <= N; ++z) {
                cin >> A[x][y][z];
            }
        }
    }

    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            for (int z = 1; z <= N; ++z) {
                P[x][y][z] = A[x][y][z]
                           + P[x - 1][y][z] + P[x][y - 1][z] + P[x][y][z - 1]
                           - P[x - 1][y - 1][z] - P[x - 1][y][z - 1] - P[x][y - 1][z - 1]
                           + P[x - 1][y - 1][z - 1];
            }
        }
    }

    cin >> Q;
    while (Q--) {
        int Lx, Rx, Ly, Ry, Lz, Rz;
        cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;
        
        int sum = P[Rx][Ry][Rz]
                - (Lx > 1 ? P[Lx - 1][Ry][Rz] : 0)
                - (Ly > 1 ? P[Rx][Ly - 1][Rz] : 0)
                - (Lz > 1 ? P[Rx][Ry][Lz - 1] : 0)
                + (Lx > 1 && Ly > 1 ? P[Lx - 1][Ly - 1][Rz] : 0)
                + (Lx > 1 && Lz > 1 ? P[Lx - 1][Ry][Lz - 1] : 0)
                + (Ly > 1 && Lz > 1 ? P[Rx][Ly - 1][Lz - 1] : 0)
                - (Lx > 1 && Ly > 1 && Lz > 1 ? P[Lx - 1][Ly - 1][Lz - 1] : 0);
        
        cout << sum << endl;
    }

    return 0;
}
