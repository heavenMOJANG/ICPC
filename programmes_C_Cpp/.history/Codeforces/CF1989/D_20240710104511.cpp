#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=1000010;
int n,m,a[N],b[N],c[N],h[N],dp[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
        cin>>b[i];
        b[i]=a[i]-b[i];
        h[a[i]]=min(h[a[i]],b[i]);
    }
    for(int i=1;i<=m;++i) cin>>c[i];
    int minn=LLONG_MAX;
    fill(dp,dp+N,LLONG_MAX);
    for(int i=1;i<=1000000;++i){
        minn=min(minn,h[i]);
        if(minn<=i) dp[i]=dp[i-minn]+1;
    }
    pair<int,int> tmp={LLONG_MAX,LLONG_MAX};
    for(int i=1;i<=n;++i) tmp=min(tmp,{b[i],a[i]});
    int ans=0;
    for(int i=1;i<=m;++i){
        auto [x,y]=tmp;
        if(c[i]>=y) ans+=(c[i]-y+x-1)/x,c[i]-=(c[i]-y+x-1)/x*x;
        ans+=dp[c[i]];
    }
    cout<<ans*2<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;//cin>>_;
    while(_--) solve();
    return 0;
}