#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    vector<int>pre(n+2,1),suf(n+2,1);
    for(int i=1;i<=n;++i) pre[i]=pre[i-1]&(a[i]==i);
    for(int i=n;i>=1;--i) suf[i]=suf[i+1]&(a[i]==i);
    auto check=[&](int l,int r){
        return pre[max(1ll,l-n)-1]&&suf[min(n,r-1)+1];
    };
    int ans=0;
    for(int i=1,j=1;i<=2*n;++i){
        j=max(j,i+1);
        while(j<=2*n&&!check(i,j)) j++;
        ans+=2*n-j+1;
    }
    vector<int>s(n+1,0),cnt(2*n+1);
    for(int i=1;i<=n;++i){
        s[i]=s[i-1]+(a[i]==i);
        if(a[i]!=i) cnt[a[i]+i]+=1;
    }
    for(int i=1;i<=2*n;++i){
        int l=max(1ll,i-n);
        int r=min(n,i-1);
        if(l>r) ans+=pre[n];
        else if(s[r]-s[l-1]+cnt[i]==r-l+1) ans+=(pre[l-1]&&suf[r+1]);
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}