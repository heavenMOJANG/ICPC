#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,q;cin>>n>>q;
    vector<int>s(n+1),cnt1(n+1);
    for(int i=1,x;i<=n;++i){
        cin>>x;
        s[i]=s[i-1]+x;
        cnt1[i]=cnt1[i-1]+(x==1);
    }
    while(q--){
        int l,r;cin>>l>>r;
        if(l==r){cout<<"NO\n";continue;}
        int t=s[r]-s[l-1]-(r-l+1);
        cout<<(t>=cnt1[r]-cnt1[l-1]?"YES\n":"NO\n");
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
