#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct Node{int a,b;};
void solve(){
    int n;cin>>n;
    vector<Node>v(n);
    for(int i=0;i<n;++i) cin>>v[i].a;
    for(int i=0;i<n;++i) cin>>v[i].b;
    sort(v.begin(),v.end(),[](const Node&x,const Node&y){return x.a<y.a;});
    for(int i=0;i<n;++i) cout<<v[i].a<<" \n"[i==n-1];
    for(int i=0;i<n;++i) cout<<v[i].b<<" \n"[i==n-1];
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
