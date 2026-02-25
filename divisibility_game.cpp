#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n), b(m);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        
        int maxVal = n + m;
        vector<bool> inA(maxVal + 1, false);
        for(int x : a) inA[x] = true;
        
        vector<bool> hasDivisorInA(maxVal + 1, false);
        for(int x = 1; x <= maxVal; x++){
            if(!inA[x]) continue;
            for(int mult = x; mult <= maxVal; mult += x){
                hasDivisorInA[mult] = true;
            }
        }

        vector<int> uniqueA;
        {
            set<int> sa(a.begin(), a.end());
            uniqueA.assign(sa.begin(), sa.end());
        }
        int numUnique = uniqueA.size();
        
        vector<int> divCount(maxVal + 1, 0);
        for(int x : uniqueA){
            for(int mult = x; mult <= maxVal; mult += x){
                divCount[mult]++;
            }
        }
        
        int alice_only = 0, bob_only = 0, common = 0;
        for(int y : b){
            bool aliceCan = hasDivisorInA[y];
            bool allDivide = (divCount[y] == numUnique);
            bool bobCan = !allDivide; 
            
            if(aliceCan && bobCan) common++;
            else if(aliceCan && !bobCan) alice_only++;
            else if(!aliceCan && bobCan) bob_only++;
        }
        
        int a_pool = alice_only, b_pool = bob_only, c_pool = common;
        bool alice_turn = true;
        bool alice_wins = false;
        
        while(true){
            if(alice_turn){
                // Alice's turn: she can take from c_pool or a_pool
                if(c_pool > 0){
                    c_pool--;
                } else if(a_pool > 0){
                    a_pool--;
                } else {
                    // Alice can't move, Bob wins
                    alice_wins = false;
                    break;
                }
            } else {
                // Bob's turn: he can take from c_pool or b_pool
                if(c_pool > 0){
                    c_pool--;
                } else if(b_pool > 0){
                    b_pool--;
                } else {
                    // Bob can't move, Alice wins
                    alice_wins = true;
                    break;
                }
            }
            alice_turn = !alice_turn;
        }
        
        cout << (alice_wins ? "Alice" : "Bob") << "\n";
    }
}