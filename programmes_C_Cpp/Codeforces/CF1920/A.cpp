#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    int l=1,r=1e9;
    set<int>s;
    for(int i=0,a,x;i<n;++i){
        cin>>a>>x;
        switch(a){
            case 1:l=max(l,x);break;
            case 2:r=min(r,x);break;
            case 3:s.insert(x);break;
        }
    }
    int cnt=0;
    for(auto x:s) if(l<=x&&x<=r) cnt++;
    cout<<max(0ll,r-l+1-cnt)<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
