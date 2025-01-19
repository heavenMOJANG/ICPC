#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;
    while(cin>>n,n){
        multiset<int>ms;
        int ans=0;
        for(int i=0,k;i<n;++i){
            cin>>k;
            for(int j=0,x;j<k;++j) cin>>x,ms.insert(x);
            int minn=*ms.begin(),maxn=*(--ms.end());
            ans+=maxn-minn;
            ms.erase(--ms.end());
            ms.erase(ms.begin());
        }
        cout<<ans<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
