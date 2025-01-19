#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    map<int,int>mp;
    for(int i=0;i<n;++i) cin>>a[i],mp[a[i]]++;
    int head=0,cnt=0,flag=0;
    for(auto [x,y]:mp)
        if(x==head+1){
            cnt++;
            head=x;
        }
        else{
            flag=1;break;
        }
    if(flag) cout<<(cnt&1?"Bob\n":"Alice\n");
    else cout<<(cnt&1?"Alice\n":"Bob\n");
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}