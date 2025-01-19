#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;
constexpr int inf=0x7fffffff;
struct Node{
    int num,val;
    bool operator<(const Node&x)const{return val==x.val?num<x.num:val<x.val;}
};
void solve(){
    int n;cin>>n;
    vector<int>tree(n+1,0),a(n+1),b(n+1),rank(n+1);
    vector<Node>c(n+1);
    map<int,int>mp;
    for(int i=1;i<=n;++i) cin>>a[i],mp[a[i]]=i;
    for(int i=1;i<=n;++i) cin>>b[i];
    for(int i=1;i<=n;++i)
        if(mp.count(b[i])!=1){cout<<"NO\n";return;}
        else c[i].val=mp[a[i]],c[i].num=i;
    int cnt=0;
    auto update=[&](int x,int d){
        while(x<=n) tree[x]+=d,x+=lowbit(x);
    };
    auto summarize=[&](int x){
        int res=0;
        while(x) res+=tree[x],x-=lowbit(x);
        return res;
    };
    for(int i=n;i;--i) update(c[i].val,1),cnt+=summarize(c[i].val-1);
    cout<<(cnt&1?"NO\n":"YES\n");
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}