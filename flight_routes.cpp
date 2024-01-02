#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> edge; //destn, weight
typedef pair<ll,int> node; //price, node
const int maxN = 2e5+1;

int N, M, K, cnt[maxN];
vector<edge> G[maxN];
priority_queue<node, vector<node>, greater<node>> Q; //min heap

int main(){
    cin>>N>>M>>K;
    for(int i = 0, a, b, c; i < M; i++){
        cin>>a>>b>>c;
        G[a].push_back({b, c});
    }

    Q.push({0, 1});
    while(!Q.empty()){
        ll d = get<0>(Q.top()); //pair's first elem
        int u = get<1>(Q.top()); //pair's second elem
        Q.pop();

        cnt[u]++;
        if(u == N){
            printf("%lld%c", d, (" \n")[cnt[u]==K]);
            if(cnt[u] == K) return 0;
        }

        if(cnt[u] <= K){
            for(edge e : G[u]){
                int v = e.first;
                ll w = e.second;
                Q.push({d+w, v});
            }
        }
    }
}