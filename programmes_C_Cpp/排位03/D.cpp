#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    int flag=1;
    vector<int>a(n),b(m);
	for(int i=0;i<n;++i) cin>>a[i];
	cin>>b[0];
	for(int i=1;i<m;++i) cin>>b[i],b[0]=__gcd(b[0],b[i]);
	for(int i=1;i<n;++i) if(a[i]%b[0]!=a[i-1]%b[0]) flag=0;
    cout<<(flag?"Yes\n":"No\n");
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
