#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(n+1),b(n+1);
    vector<pair<int,int>>v;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i],v.push_back({b[i],a[i]});
    if(n==1){cout<<m<<"\n";return;}
    sort(v.begin(),v.end(),[](const pair<int,int>&x, const pair<int,int>&y){
        return x.first==y.first?x.second<y.second:x.first<y.first;
    });
    int sum=1,ans=m,lst=m;
    for(auto t:v)
        if(t.first<m&&sum<n){
            lst=t.first;
            int tmp=min(t.second,n-sum);
            sum+=tmp;
            ans+=tmp*t.first;
        }
    if(sum<n) ans+=(n-sum)*m;
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
