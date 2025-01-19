#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int suf[100005][30][2];
void solve(){
    int n;cin>>n;
    vector<int>a(n+1),s(n+1);
    for(int i=1;i<=n;++i) cin>>a[i],s[i]=s[i-1]^a[i];
    memset(suf[n+1],0,sizeof(suf[n+1]));
    for(int i=n;i>=1;--i){
        memcpy(suf[i],suf[i+1],sizeof(suf[i+1]));
        for(int j=0;j<30;++j) suf[i][j][s[i]>>j&1]+=1;
    }
    int cnt[30][2]{};
    for(int i=0;i<30;++i) cnt[i][0]+=1;
    int ans=0;
    for(int i=1;i<=n;++i){
        int t=__lg(a[i]);
        for(int j=0;j<2;++j) ans+=suf[i][t][j]*cnt[t][j];
        for(int j=0;j<30;++j) cnt[j][s[i]>>j&1]+=1;
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}