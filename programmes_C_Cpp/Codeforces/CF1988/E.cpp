#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1),p(n+1);
    for(int i=1;i<=n;++i) cin>>a[i],p[a[i]]=i;
    set<int>s;
    s.insert(0);s.insert(n+1);
    vector<int>cnt(n+1),d(n+1);
    int sum=0;
    auto add=[&](int l,int r,int v){
        if(l>r) return;
        d[l]+=v;
        if(r+1<=n) d[r+1]-=v;
    };
    for(int i=1;i<=n;++i){
        int u=p[i];
        int L=*prev(s.lower_bound(u));
        int R=*s.upper_bound(u);
        cnt[u]=i*(u-L)*(R-u);
        sum+=cnt[u];
        add(L+1,u-1,-i*(R-u));
        add(u+1,R-1,-i*(u-L));
        auto it=s.upper_bound(u);
        if(it!=s.end()){
            auto nxt=next(it);
            if(nxt!=s.end()){
                int p1=*it,p2=*nxt;
                cnt[p1]-=i*(p2-p1-1)*(u-L);
            }
        }
        it=s.lower_bound(u);
        if(it!=s.begin()){
            it=prev(it);
            if(it!=s.begin()){
                auto pre=prev(it);
                int p1=*it,p2=*pre;
                cnt[p1]-=i*(p1-p2-1)*(R-u);
            }
        }
        s.insert(u);
    }
    for(int i=1;i<=n;++i){
        d[i]+=d[i-1];
        cout<<sum-cnt[i]+d[i]<<" \n"[i==n];
    }
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}