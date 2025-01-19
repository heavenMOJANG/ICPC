#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=5e5+10;
vector<int>a(N,cnt(N),f[N],v1[N],v2[N];
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        int g=__gcd(a[i],i);
        int x=i/g,y=a[i]/g;
        v1[x].emplace_back(y);
        v2[y].emplace_back(x);
    }
    long long ans=0;
    for(int xi=1;xi<=n;++xi){
        for(int yi:v1[xi]) for(int xj:f[yi]) cnt[xj]++;
        for(int yj=xi;yj<=n;yj+=xi) for(auto x:v2[yj]) ans+=cnt[x];
        for(int yi:v1[xi]) for(int xj:f[yi]) cnt[xj]=0;
    }
    for(int i=1;i<=n;++i) ans-=(__gcd(a[i],i)==i);
    cout<<ans/2<<"\n";
    for(int i=1;i<=n;++i) v1[i].clear(),v2[i].clear();
    return;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=1;i<N;++i)
        for(int j=i;j<N;j+=i) f[j].emplace_back(i);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}