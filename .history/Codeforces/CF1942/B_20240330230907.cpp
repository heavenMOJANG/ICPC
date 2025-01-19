#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n),p(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int minn=*min_element(a.begin(),a.end());
    set<int>s;
    for(int i=0;i<n;++i) s.insert(i);
    for(int i=0;i<n;++i){
        p[i]=*s.begin()-(a[i]-minn);
        s.erase(p[i]);
    }
    for(int i=0;i<n;++i) cout<<p[i]<<" \n"[i==n-1];
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
