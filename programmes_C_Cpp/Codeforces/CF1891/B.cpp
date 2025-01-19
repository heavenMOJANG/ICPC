#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(n),b(m);
    vector<int>fac(40),now(40),s(40);
    fac[0]=1;
    for(int i=1;i<=30;++i) fac[i]=fac[i-1]*2,now[i]=40;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<m;++i){
        cin>>b[i];
        for(int j=b[i];j<=30;j++)
            if(now[j]>b[i]) now[j]=b[i],s[j]+=fac[b[i]-1];
    }
    for(int i=0;i<n;++i){
        for(int j=30;j>=0;j--)
            if(a[i]%fac[j]==0){a[i]+=s[j];break;}
        cout<<a[i]<<" \n"[i==n-1];
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
