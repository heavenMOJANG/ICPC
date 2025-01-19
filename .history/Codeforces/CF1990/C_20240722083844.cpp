#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    map<int,int>mp;
    int maxn=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        mp[a[i]]++;
        if(mp[a[i]]>=2) maxn=max(maxn,a[i]);
        a[i]=maxn;
    }
    mp.clear();
    maxn=0;
    int sum=0,ans=0;
    for(int i=0,x;i<n;++i){
        x=a[i];
        ans+=x;
        mp[x]++;
        if(mp[x]>=2) maxn=max(maxn,x);
        a[i]=maxn;
        sum+=maxn;
    }
    while(!a.empty()){
        ans+=sum;
        sum-=a.back();
        a.pop_back();
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}