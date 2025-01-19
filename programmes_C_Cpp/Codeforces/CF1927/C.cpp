#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m,k;cin>>n>>m>>k;  
    vector<int>a(n+1),b(m+1);
    for(int i=1;i<=n;++i) cin>>a[i];  
    for(int i=1;i<=m;++i) cin>>b[i];  
    sort(a.begin()+1,a.end());  
    sort(b.begin()+1,b.end()); 
    a.erase(unique(a.begin()+1,a.end()),a.end());
    b.erase(unique(b.begin()+1,b.end()),b.end());
    n=a.size()-1,m=b.size()-1;
    vector<int>cnt(k+1);
    map<int,int>mp;
    for(int i=1;i<=n;++i)
        if(a[i]<=k) cnt[a[i]]++,mp[a[i]]++;
        else break;
    for(int i=1;i<=m;++i)
        if(b[i]<=k) cnt[b[i]]++;
        else break;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=k;++i){
        if(cnt[i]==2) continue;
        if(cnt[i]==0){cout<<"NO\n";return;}
        if(mp[i]) cnt1++;
        else cnt2++;
    }
    cout<<(cnt1<=k/2&&cnt2<=k/2?"YES\n":"NO\n");
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
