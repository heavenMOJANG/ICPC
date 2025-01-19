#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<int>a(n),b(m);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int j=0;j<m;++j) cin>>b[j];
    map<int,int>bCnt,cCnt;
    for(auto x:b) bCnt[x]++;
    int cur=0;
    for(int i=0;i<m;++i){
        cCnt[a[i]]++;
        if(bCnt[a[i]]&&cCnt[a[i]]<=bCnt[a[i]]) cur++;
    }
    int ans=(cur>=k);
    for (int i=m;i<n;++i) {
        if (bCnt[a[i]]&&cCnt[a[i]]<bCnt[a[i]]) cur++;
        cCnt[a[i]]++;
        if (bCnt[a[i-m]]&&cCnt[a[i-m]]<=bCnt[a[i-m]]) cur--;
        cCnt[a[i-m]]--;
        ans+=(cur>=k);
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}