#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> blogs(n);
        
        for(int i = 0; i < n; i++){
            int l; cin >> l;
            blogs[i].resize(l);
            for(auto& x : blogs[i]) cin >> x;
        }
        
        vector<int> Q;
        vector<bool> used(n, false);
        set<int> placed;
        
        for(int step = 0; step < n; step++){
            int best = -1;
            vector<int> best_front;
            
            for(int i = 0; i < n; i++){
                if(used[i]) continue;
                
                vector<int> front;
                set<int> seen;
                for(int j = blogs[i].size()-1; j >= 0; j--){
                    int u = blogs[i][j];
                    if(!placed.count(u) && !seen.count(u)){
                        seen.insert(u);
                        front.push_back(u);
                    }
                }
                
                if(best == -1){
                    best = i; best_front = front;
                } else {
                    bool cur_empty = best_front.empty();
                    bool new_empty = front.empty();
                    if(cur_empty && !new_empty){        // prefer non-empty
                        best = i; best_front = front;
                    } else if(!cur_empty && new_empty){ // keep current
                    } else if(front < best_front){      // both same: lex compare
                        best = i; best_front = front;
                    }
                }
            }
            
            used[best] = true;
            for(int u : best_front){ Q.push_back(u); placed.insert(u); }
        }
        
        for(int i = 0; i < (int)Q.size(); i++)
            cout << Q[i] << " \n"[i+1==(int)Q.size()];
    }
    return 0;
}