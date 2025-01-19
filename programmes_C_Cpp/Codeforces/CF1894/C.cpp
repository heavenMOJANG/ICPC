#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n,k,a[200010],v[200010];
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    int now=n,tag=1;
    while(k){
        if(v[now]) break;
        v[now]=1;
        if(a[now]>n){tag=0;break;}
        now-=a[now];
        if(now<=0) now+=n;
        k--;
    }
    cout<<(tag?"YES\n":"NO\n");
    for(int i=1;i<=n;i++) v[i]=0;
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
