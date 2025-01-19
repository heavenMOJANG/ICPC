#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int a[200010],ans[200010];
void solve(){
    int n,m;cin>>n>>m;
    string s;
    for(int i=1;i<=n;++i) cin>>a[i];
    cin>>s;
    int l=1;
    for(int i=0;i<n;i++) if(s[i]=='L') ++l;
    int r=l,cur=1;
    for(int i=n-1;i>=0;--i){
        if(s[i]=='L') cur=(cur*a[--l])%m;
        else cur=(cur*a[r++])%m;
        ans[i]=cur;
    }
    for(int i=0;i<n;++i) cout<<ans[i]<<" \n"[i==n-1];
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
