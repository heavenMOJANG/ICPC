#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int idx,tree[2][400010],n,a[400010],ans[400010];
void insert(int x){
    int p=0;
    for(int j=20;j>=0;--j){
        int u=(x>>j)&1;
        if(!tree[u][p]) tree[u][p]=++idx;
        p=tree[u][p];
    }
}
int query(int x){
    int p=0,mx=0;
    for(int j=20;j>=0;--j){
        int u=(x>>j)&1;
        if(tree[!u][p]) mx|=(1<<j),p=tree[!u][p];
        else
            if (tree[u][p]) p=tree[u][p];
            else return 0;
        if(mx>=n) return 0;
    }
    return (mx==(n-1));
}
void solve(){
    cin>>n;
    int orx=0;
    for(int i=1;i<n;++i){
        cin>>a[i];
        orx^=a[i];
        insert(orx);
    }
    ans[0]=n-1;
    for(int i=0;i<n;++i) if(query(i)){ans[0]=i;break;}
    for(int i=1;i<=n;++i) ans[i]=ans[i-1]^a[i];
    for(int i=0;i<n;++i) cout<<ans[i]<<" ";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
