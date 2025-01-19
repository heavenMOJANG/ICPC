#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    set<int>s;s.insert(1);
    vector<int>prime,vis(70,1);
    function<void(int)>euler=[&](int x){
        vis[1]=0;
        for(int i=2;i<=x;++i){
            if(vis[i]) prime.push_back(i);
            for(int j=0;j<prime.size()&&i*prime[j]<=x;++j){
                vis[i*prime[j]]=0;
                if(i%prime[j]==0) break;
            }
        }
    };
    euler(64);
    for(int i=2;i<65536;++i){
        int x=-1,k=-1;
        while(x) x/=i,k++;
        int res=i;
        for(int j=2;j<=k;++j){
            res*=i;
            if(!vis[j]) s.insert(res);
        }
    }
    for(auto it=s.begin();it!=s.end();++it) cout<<*it<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
