#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int p[4000010],e[4000010],s[4000010],f[4000010];
void prime(int x){
    p[0]=p[1]=1;
    for(int i=2;i*i<=4000000;++i)
        if(!p[i]) for(int j=i*i;j<=4000000;j+=i) p[j]=1;
}
void phi(int x){
    for(int i=1;i<=x;++i) e[i]=i;
    for(int i=2;i<=x;i++)
        if(!p[i]) for(int j=i;j<=x;j+=i) e[j]=e[j]/i*(i-1);
}
void solve(){
    prime(4000000);
    phi(4000000);
    for(int i=1;i<=4000000;++i)
        for(int j=i*2;j<=4000000;j+=i) s[j]+=e[j/i]*i;
    for(int i=2;i<=4000000;++i) f[i]=f[i-1]+s[i];
    int n;
    while(cin>>n&&n) cout<<f[n]<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
