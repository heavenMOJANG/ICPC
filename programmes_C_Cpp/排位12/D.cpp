#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(2*n,0),vis(2*n,0);
    map<int,int>mp;
    int cnt=0;
    for(int i=0,l,r;i<n;++i){
        cin>>l>>r;
        if(!mp.count(l)) mp[l]=cnt++;
        if(!mp.count(r)) mp[r]=cnt++;
        a[mp[l]]=mp[r],vis[mp[l]]=1;
    }
    int res=0;
    for(int i=0;i<cnt;++i)
        if(vis[i]){
            int p=i;
            res++;
            do{vis[p]=0,p=a[p];}while(p!=i);
        }
    cout<<n-res<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
