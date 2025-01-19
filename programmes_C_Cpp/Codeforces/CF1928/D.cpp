#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,b,x;cin>>n>>b>>x;
    vector<int>a(n+10);
    int sum=0,p=0;
    map<int,int>mp;
    for(int i=0;i<n;++i){
        cin>>a[i];
        p=max(p,a[i]);
        mp[a[i]]++;
    }
    int maxn=0;
    for(int i=p;i>=1;--i){
       int sum=0;
       for(auto e:mp){
           int x=e.first/i;
           int cnt=e.first%i;
           sum+=(e.first*(e.first-1)/2-(cnt*(x+1)*x/2+(i-cnt)*x*(x-1)/2))*e.second;
       }
       maxn=max(maxn,sum*b-(i-1)*x);
    }
    cout<<maxn<<endl;
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
