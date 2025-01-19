#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,f,a,b;cin>>n>>f>>a>>b;
    vector<int>m(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>m[i];
        if(f<=0) continue;
        if((m[i]-m[i-1])*a>b)f-=b;
        else f-=(m[i]-m[i-1])*a;
    }
    cout<<(f>0?"YES\n":"NO\n");
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
