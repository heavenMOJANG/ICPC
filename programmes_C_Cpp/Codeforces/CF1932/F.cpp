#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct line{int l,r;};
int dif[1000010],dp[1000010],lft[1000010],pre[1000010];
vector<line> lines;
void solve(){
    lines.clear();
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n+1;i++) dif[i]=0;
    lines.resize(m);
    for(int i=0;i<m;i++){
        cin>>lines[i].l>>lines[i].r;
        dif[lines[i].l]++;
        dif[lines[i].r+1]--;
    }
    sort(lines.begin(),lines.end(),[](const auto&x,const auto&y){return x.l<y.l;});
    int j=1;
    for(int i=0;i<m;++i){
        while(j<=n&&j<lines[i].l) ++j;
        while(j<=n&&j<=lines[i].r){lft[j]=lines[i].l;++j;}        
    }
    dp[0]=0;pre[0]=0;
    int ans=0;
    for(int i=1;i<=n;++i){
        dif[i]+=dif[i-1];
        if(!dif[i]) dp[i]=pre[i-1];
        else dp[i]=dif[i]+pre[lft[i]-1];
        pre[i]=max(pre[i-1],dp[i]);
        ans=max(ans,dp[i]);
    }
    cout<<ans<<'\n';
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
