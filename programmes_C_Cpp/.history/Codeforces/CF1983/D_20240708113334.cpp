#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct Node{
    int num,val;
    bool operator<(const Node&x)const{return val==x.val?num<x.num:val<x.val;}
};
void solve(){
    int n;cin>>n;
    vector<int>tree(n+1),a(n+1),rank(n+1);
    vector<Node>b(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i].val,b[i].num=i;

}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}