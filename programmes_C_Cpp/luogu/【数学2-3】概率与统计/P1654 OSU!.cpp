#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<double>a(n+1,0.0),b(n+1,0.0),c(n+1,0.0);
    for(int i=1;i<=n;++i){
        double p;cin>>p;
        a[i]=p*(a[i-1]+1);
		b[i]=p*(b[i-1]+2*a[i-1]+1);
		c[i]=c[i-1]+p*(3*b[i-1]+3*a[i-1]+1);
    }
    cout<<fixed<<setprecision(1)<<c[n]<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
