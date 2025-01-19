#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct Node{int l,r;};
void solve(){
    int n;cin>>n;
    vector<Node>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i].l>>a[i].r;
    sort(a.begin()+1,a.begin()+1+n,[](const Node&x,const Node&y){return x.l<y.l;});
    auto lowbit=[&](int x){return x&(-x);};
    vector<int>t(n+1,0);
    function<void(int,int)> update=[&](int x,int d){while(x<=n) t[x]+=d,x+=lowbit(x);};
    auto sum=[&](int x){int res=0;while(x) res+=t[x],x-=lowbit(x);return res;};
    for(int i=1;i<=n;++i) a[i].l=i;
    vector<int>r(n+1,0);
    sort(a.begin()+1,a.begin()+1+n,[](const Node&x,const Node&y){return x.r<y.r;});
    for(int i=1;i<=n;++i) r[a[i].l]=i;
    int res=0;
    for(int i=n;i;--i){
        update(r[i],1);
        res+=sum(r[i]-1);
    }
    cout<<res<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
