#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    int cnt=0;
    for(int i=0;i<n;++i) cin>>a[i];
    int minn=LLONG_MAX;
    for(int i=0;i<n;++i){
        int t=k-(a[i]+k)%k;
        if((a[i]%k)==0) t=0;
        minn=min(minn,t);
    }
    if(k==4){
        for(int i=0;i<n;++i) if(a[i]&1) cnt ++;
        if(n-cnt>1) minn=0;
        else if((n-cnt)==1&&cnt>=1) minn=min(minn, 1ll);
        else if(cnt>=2) minn=min(minn,2ll);
    }
    cout<<minn<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
