#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        vector<long long> a(n+1);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        
        int cnt[2]={};
        for(int i=0;i<m;i++){
            int x; scanf("%d",&x);
            cnt[x%2]++;
        }
        
        vector<long long> elems[2];
        for(int i=1;i<=n;i++) elems[i%2].push_back(a[i]);
        for(int p=0;p<2;p++) sort(elems[p].begin(),elems[p].end(),greater<long long>());
        
        long long ans=0;
        for(int p=0;p<2;p++){
            long long psum=0;
            for(auto v: elems[p]) psum+=v;
            
            if(cnt[p]==0){
                ans+=psum;
                continue;
            } 
            
            int maxMark=min(cnt[p],(int)elems[p].size());
            long long markedSum=0;
            for(int j=0;j<maxMark;j++){
                if(j==0 || elems[p][j]>0) markedSum+=elems[p][j];
                else break;
            }
            ans+=psum-markedSum;
        }
        printf("%lld\n",ans);
    }
}