#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int a[1000010],f[1000010],vis[1000010],cnt[1000010];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;++i) f[i]=vis[i]=cnt[i]=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        cnt[a[i]]++;
        vis[a[i]]=1;
    }
    for(int i=n;i>=1;--i){
        int cur=0;
        for(int j=i;j<=n;j+=i){
            cur+=cnt[j];
            f[i]-=f[j];
            vis[j]|=vis[i];
        }
        f[i]+=cur*(cur-1)/2;
    }
    int res=0;
    for(int i=1;i<=n;++i) if(!vis[i]) res+=f[i];
    cout<<res<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
