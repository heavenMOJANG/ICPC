#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,c;cin>>n>>c;
    vector<int>a(n+1);
    vector<pair<int,int>>b(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=2;i<=n;i++) b[i-1].first=c*i-a[i],b[i-1].second=i;
    sort(b.begin()+1,b.begin()+n);
    int sum=a[1],flag=1;
    for(int i=1;i<n;++i)
        if(sum>=b[i].first) sum+=a[b[i].second];
        else flag=0;
    cout<<(flag?"YES\n":"NO\n");
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
