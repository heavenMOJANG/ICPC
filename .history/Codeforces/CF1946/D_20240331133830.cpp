#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>v(n+1),w(n+1),s(n+1);
    int sz=__lg(m+10);
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++) w[i]^=w[i-1];
    for(int i=1;i<=n-1;i++) v[i] = 1; v[n] = inf;
    int ans=0;
    for(int i=1;i<=n;i++) if((w[i]|m)==m) ans += v[i];
    for(int i=0;i<=sz;i++){
        if(m>>i&1){
            int u=(m-(1ll<<i))|((1ll<<i)-1);
            int tmp=0;
            for(int j=1;j<=n;++j) if((w[j]|u)==u) tmp+=v[j];
            ans=max(ans,tmp);
        }
    }
    int tmp=inf;
    if(ans-tmp+1<0) cout<<-1<<"\n";
    else cout<<ans-tmp+1<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
