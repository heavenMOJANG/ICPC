#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct Node{int val,idx;};
int cmp(Node x,Node y){return x.val>y.val;}
void solve(){
    int n,x;cin>>n>>x;
    vector<int>b(n);
    vector<Node>a(n);
    for(int i=0;i<n;++i) cin>>a[i].val,a[i].idx=i;
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n;++i) cin>>b[i];
    sort(b.begin(),b.end());
    cout<<"YES\n";
    for(int i=0;i<n;++i)
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
