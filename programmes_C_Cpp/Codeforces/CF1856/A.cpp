#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a[60];
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    ll maxn=0;
    for(ll i=n;i>1;--i) if(a[i]<a[i-1]) maxn=max(maxn,a[i-1]);
	cout<<maxn<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    cin>>_;
    while(_--) solve();
    return 0;
}