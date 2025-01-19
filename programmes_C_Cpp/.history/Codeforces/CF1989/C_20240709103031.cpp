#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    vector<int>cur(2),cnt(2);
    for(int i=0;i<n;++i)
        if(a[i]==b[i]){
            if(a[i]==1) cnt[0]++;
            else if(a[i]==-1) cnt[1]++;
        }
        else{
            if(a[i]==1) cur[0]++;
            else if(b[i]==1) cur[1]++;
        }
    if(cur[0]>cur[1]) swap(cur[0],cur[1]);
    while(cur[0]<cur[1]&&cnt[0]>0) cnt[0]--,cur[0]++;
    while(cur[0]<cur[1]&&cnt[1]>0) cur[1]--,cnt[1]--;
    int res=cnt[0]-cnt[1];
    if(res){
        res/=2;
        if(cur[0]==cur[1]) cout<<cur[0]+res<<"\n";
    }
    else cout<<cur[0]<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}