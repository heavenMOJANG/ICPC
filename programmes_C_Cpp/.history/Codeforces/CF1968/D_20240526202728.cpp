#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k,l,r;cin>>n>>k>>l>>r;
    l--,r--;
    vector<int>p(n),a(n);
    for(int i=0;i<n;++i) cin>>p[i],p[i]--;
    for(int i=0;i<n;++i) cin>>a[i];
    int lMax=0,rMax=0,pl=0,pr=0;
    int minn=min(n,k);
    for(int i=0;i<minn;++i){
        int lCur=pl+a[l]*k;
        lMax=max(lMax,lCur);
        pl+=a[l],l=p[l];
        int rCur=pr+a[r]*k;
        rMax=max(rMax,rCur);
        pr+=a[r],r=p[r];
        k--;
    }
    if(lMax>rMax) cout<<"Bodya\n";
    if(rMax>lMax) cout<<"Sasha\n";
    if(lMax==rMax) cout<<"Draw\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}