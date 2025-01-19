#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Node{
    ll idx,val;
    bool operator<(const Node&b)const{return val<b.val;}
}a[100010];
ll n;
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i].val,a[i].idx=i;
    sort(a+1,a+1+n);
    ll res=0;
    for(ll i=1;i<n;++i) if(a[i].idx>a[i+1].idx) res++;
    cout<<res<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
