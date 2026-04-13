#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        
        int maxRun = 1, curRun = 1;
        for(int i = 1; i < n; i++){
            if(a[i] == a[i-1]) curRun++;
            else curRun = 1;
            maxRun = max(maxRun, curRun);
        }
        
        cout << (maxRun < m ? "YES" : "NO") << "\n";
    }
    return 0;
}