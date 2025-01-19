#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,c;cin>>n>>c;
    vector<int>a(n),id(n),pre(n);
    for(int i=0;i<n;++i) cin>>a[i],pre[i]=a[i],id[i]=i;
    for(int i=1;i<n;++i) pre[i]+=pre[i-1];
    vector<int>ans(n,n-1),suf=a;
    suf.emplace_back(0);
    for(int i=n-1;i>=0;--i) suf[i]=max(suf[i],suf[i+1]);
    for(int i=0;i<n;++i)
        if(pre[i]+c>=suf[i+1]) ans[i]=i;
        else ans[i]=i+1;
    sort(id.begin(),id.end(),[&](int x,int y){return a[x]!=a[y]?a[x]>a[y]:x<y;});
    int sum=c,cnt=0;
    set<int>s;
    for(int i=0;i<n;++i) s.insert(i);
    for(auto x:id){
        if(*s.begin()!=x){
            if(a[*s.begin()]+sum<a[x]) ans[x]=min(ans[x],cnt);
        }
        cnt++;
        sum+=a[x];
        s.erase(x);
    }
    for(int i=0;i<n;++i) cout<<ans[i]<<" \n"[i==n-1];
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}