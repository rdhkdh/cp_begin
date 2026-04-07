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
        vector<int> p(n+1), d(n+1);
        for(int i=1;i<=n;i++) cin >> p[i];
        for(int i=1;i<=n;i++) cin >> d[i];
        
        vector<int> cnt(n+1, 0);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(p[j]>p[i]) cnt[i]++;
        
        bool ok = true;
        for(int i=1;i<=n;i++)
            if(d[i] > cnt[i]){ ok = false; break; }
        
        if(!ok){ cout << -1 << "\n"; continue; }
        
        vector<int> need(n+1);
        for(int i=1;i<=n;i++) need[i] = cnt[i] - d[i];
        
        vector<vector<int>> dominates(n+1);
        for(int i=1;i<=n;i++)
            for(int l=1;l<i;l++)
                if(p[l]<p[i]) dominates[i].push_back(l);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=1;i<=n;i++)
            if(need[i]==0) pq.push(i);
        
        vector<int> q(n+1, 0);
        vector<bool> placed(n+1, false);
        int rank_val = 1;
        
        while(!pq.empty()){
            int i = pq.top(); pq.pop();
            q[i] = rank_val++;
            placed[i] = true;
            for(int l : dominates[i]){
                if(!placed[l]){
                    need[l]--;
                    if(need[l]==0) pq.push(l);
                }
            }
        }
        
        if(rank_val <= n){ cout << -1 << "\n"; continue; }
        
        for(int i=1;i<=n;i++) cout << q[i] << " \n"[i==n];
    }
    return 0;
}