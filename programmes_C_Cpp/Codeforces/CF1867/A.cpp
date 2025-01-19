#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Node{ll val,rnk;};
void solve(){
    ll n;cin>>n;
    vector<Node>a(n);
    for(ll i=0;i<n;++i) cin>>a[i].val,a[i].rnk=i;
    sort(a.begin(),a.end(),[](Node x,Node y){return x.val>y.val;});
    for(ll i=0;i<n;++i) a[i].val=i+1;
    sort(a.begin(),a.end(),[](Node x,Node y){return x.rnk<y.rnk;});
    for(ll i=0;i<n;++i) cout<<a[i].val<<" \n"[i==n-1];
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
