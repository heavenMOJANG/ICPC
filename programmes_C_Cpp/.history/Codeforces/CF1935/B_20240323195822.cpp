#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1),pre(n+1),suf(n+1);
    map<int,int>mp;
    int cur=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        mp[a[i]]++;
        while(mp[cur]) cur++;
        pre[i]=cur;
    }
    mp.clear();cur=0;
    for(int i=n;i>=1;--i){
        mp[i]++;
        while(mp[cur]) cur++;
        suf[i]=cur;
    }
    for(int i=1;i<n;++i)
        if(pre[i]==suf[i+1]){
            cout<<"2\n1 "<<i<<"\n"<<i+1<<" "<<n<<"\n";
            return;
        }
    cout<<"-1\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
