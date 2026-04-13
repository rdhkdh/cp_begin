#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BIT {
    int n;
    vector<ll> t;
    BIT(int n) : n(n), t(n+1, 0) {}
    void upd(int i, ll v) { for(i++; i<=n; i+=i&-i) t[i]+=v; }
    ll qry(int i) { ll s=0; for(i++; i>0; i-=i&-i) s+=t[i]; return s; }
    ll qry(int l, int r) { return l>r?0:qry(r)-(l?qry(l-1):0); }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> p(n+1);
        for(int i=1;i<=n;i++) cin>>p[i];
        
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> fv(n+1), gv(n+1), in_t(n+1), out_t(n+1);
        vector<ll> sfsum(n+1, 0);
        
        {
            vector<bool> pres(n+1, false);
            BIT pb(n);
            int cmex=0, timer=0;
            
            auto fnext=[&](int s)->int{
                if(s>=n) return n;
                if(pb.qry(s,n-1)==n-s) return n;
                int lo=s, hi=n-1;
                while(lo<hi){
                    int mid=(lo+hi)/2;
                    if(pb.qry(lo,mid)==mid-lo+1) lo=mid+1;
                    else hi=mid;
                }
                return lo;
            };
            
            struct Fr{int v,par,ci; bool ent;};
            vector<Fr> stk;
            stk.reserve(n);
            stk.push_back({1,0,0,false});
            
            while(!stk.empty()){
                Fr& f=stk.back();
                int v=f.v, par=f.par;
                if(!f.ent){
                    f.ent=true;
                    in_t[v]=timer++;
                    pres[p[v]]=true; pb.upd(p[v],1);
                    while(cmex<n && pres[cmex]) cmex++;
                    fv[v]=cmex;
                    gv[v]=fnext(cmex+1);
                    sfsum[v]=fv[v];
                }
                bool found=false;
                while(f.ci<(int)adj[v].size()){
                    int c=adj[v][f.ci++];
                    if(c!=par){stk.push_back({c,v,0,false}); found=true; break;}
                }
                if(!found){
                    out_t[v]=timer-1;
                    pres[p[v]]=false; pb.upd(p[v],-1);
                    if(p[v]<cmex) cmex=p[v];
                    stk.pop_back();
                    if(!stk.empty()) sfsum[stk.back().v]+=sfsum[v];
                }
            }
        }
        
        ll base=sfsum[1];
        
        vector<vector<pair<int,int>>> byf(n+1);
        for(int u=1;u<=n;u++) byf[fv[u]].emplace_back(in_t[u],gv[u]);
        for(auto& v:byf) sort(v.begin(),v.end());
        
        vector<vector<ll>> psg(n+1);
        for(int k=0;k<=n;k++){
            psg[k].resize(byf[k].size()+1,0);
            for(int i=0;i<(int)byf[k].size();i++) psg[k][i+1]=psg[k][i]+byf[k][i].second;
        }
        
        auto rq=[&](int k,int l,int r)->pair<ll,ll>{
            auto& bk=byf[k];
            int lo=(int)(lower_bound(bk.begin(),bk.end(),make_pair(l,INT_MIN))-bk.begin());
            int hi=(int)(upper_bound(bk.begin(),bk.end(),make_pair(r,INT_MAX))-bk.begin());
            if(lo>=hi) return{0,0};
            return{psg[k][hi]-psg[k][lo],(ll)(hi-lo)};
        };
        
        vector<int> qv;
        for(int v=1;v<=n;v++) if(p[v]>fv[v]) qv.push_back(v);
        
        vector<ll> P2v(n+1,0);
        {
            auto qs=qv;
            sort(qs.begin(),qs.end(),[&](int a,int b){return p[a]>p[b];});
            vector<pair<int,int>> nf(n);
            for(int u=1;u<=n;u++) nf[u-1]={fv[u],u};
            sort(nf.begin(),nf.end(),greater<pair<int,int>>());
            BIT bs(n),bc(n);
            int ni=0;
            for(int v:qs){
                int x=p[v];
                while(ni<n&&nf[ni].first>x){
                    int u=nf[ni].second;
                    bs.upd(in_t[u],(ll)nf[ni].first);
                    bc.upd(in_t[u],1);
                    ni++;
                }
                ll sf=bs.qry(in_t[v],out_t[v]);
                ll cf=bc.qry(in_t[v],out_t[v]);
                P2v[v]=sf-(ll)x*cf;
            }
        }
        
        vector<ll> P1v(n+1,0);
        {
            vector<vector<int>> qbk(n+1);
            for(int v:qv) if(fv[v]<n) qbk[fv[v]].push_back(v);
            for(int k=0;k<n;k++) sort(qbk[k].begin(),qbk[k].end(),[&](int a,int b){return p[a]>p[b];});
            
            BIT p1s(n),p1c(n);
            vector<pair<int,int>> upds;
            
            for(int k=0;k<n;k++){
                if(qbk[k].empty()) continue;
                vector<pair<int,int>> nk;
                for(auto[it,g]:byf[k]) nk.emplace_back(g,it);
                sort(nk.begin(),nk.end(),greater<pair<int,int>>());
                int ni2=0;
                for(int v:qbk[k]){
                    int x=p[v];
                    while(ni2<(int)nk.size()&&nk[ni2].first>x){
                        auto[g,it]=nk[ni2++];
                        p1s.upd(it,g); p1c.upd(it,1);
                        upds.emplace_back(it,g);
                    }
                    ll sg=p1s.qry(in_t[v],out_t[v]);
                    ll cg=p1c.qry(in_t[v],out_t[v]);
                    P1v[v]=sg-(ll)x*cg;
                }
                for(auto[it,g]:upds){p1s.upd(it,-g);p1c.upd(it,-1);}
                upds.clear();
            }
        }
        
        ll best=0;
        for(int v:qv){
            int k=fv[v];
            if(k>=n) continue;
            auto[sg,cg]=rq(k,in_t[v],out_t[v]);
            ll gain=sg-(ll)k*cg-P1v[v]-P2v[v];
            best=max(best,gain);
        }
        
        cout<<base+best<<"\n";
    }
}