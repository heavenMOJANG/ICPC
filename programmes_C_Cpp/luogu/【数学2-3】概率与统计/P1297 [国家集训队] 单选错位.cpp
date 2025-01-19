#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,A,B,C;cin>>n>>A>>B>>C;
    vector<int>a(n+1);
    cin>>a[1];
    for(int i=2;i<=n;++i) a[i]=(a[i-1]*A+B)%100000001;
    for(int i=1;i<=n;++i) a[i]=a[i]%C+1;
    double res=0.0;
    for(int i=2;i<=n;++i) res+=1.0/max(a[i],a[i-1]);
    res+=1.0/max(a[1],a[n]);
    cout<<fixed<<setprecision(3)<<res<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
