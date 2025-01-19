#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,x,y;cin>>n>>x>>y;
    vector<int> a(x);
    for(int i=0;i<x;++i) cin>>a[i];
    sort(a.begin(),a.end());
    int sum=x;
    vector<int>remain[2];
    for(int i=0;i<x;++i){
        int len=a[(i+1)%x]-a[i]-1;
        if(len<0) len+=n;
        if(len==1) sum+=1;
        if(len>1) remain[len%2].push_back(len);
    }
    for(int i=1;i>=0;--i){
        sort(remain[i].begin(),remain[i].end());
        for(auto u:remain[i]){
            if (u%2==1){
                int cnt2=(u-3)/2;
                int t=min(y,cnt2);
                y-=t;
                sum+=t*2;
                int cnt3=1;
                t=min(y,cnt3);
                y-=t;
                sum+=t*3;
            }
            else{
                int cnt2=u/2;
                int t=min(y,cnt2);
                y-=t;
                sum+=t*2;
            }
        }
    }
    cout<<sum-2<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
