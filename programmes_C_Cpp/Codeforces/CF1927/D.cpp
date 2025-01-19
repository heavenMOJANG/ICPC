#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;  
    vector<int>a(n+1),s(n+1),nxt(n+1,-1);
    for(int i=1;i<=n;++i) cin>>a[i];
    int i=1;
    while(i<=n){
        int j=i;
        while(j+1<=n&&a[i]==a[j+1]) j++;
        for(int k=i;k<=j;++k) nxt[k]=j+1;
        i=j+1;
    }
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        if(nxt[l]<=r) cout<<l<<" "<<nxt[l]<<"\n";
        else cout<<"-1 -1\n";
    }
    cout<<"\n";  
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
