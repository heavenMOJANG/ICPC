#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    vector<int>prime(200000,0),vis(200010,1);
    int idx=0;
    vis[1]=0;
    for(int i=2;i<=200000;++i){
        if(vis[i]) prime[idx++]=i;
        for(int j=0;j<idx&&i*prime[j]<=200000;++j){
            vis[i*prime[j]]=0;
            if(i%prime[j]==0) break;
        }
    }
    auto sum=[&](int x)->int
    {
        int res=0;
        for(int i=0;i<idx&&prime[i]<=x;++i){
            if(vis[x]){res++;break;}
            if(x%prime[i]==0){
                res++;
                x/=prime[i];
                if(x%prime[i]==0) return -1;
            }
        }
        return res;
    };
    int n,cnt=0;
    auto cube=[&](int x){return x*x*x-1;};
    auto cal=[&](int x)->int
    {
        int tmp=sum(x);
        if(tmp==-1) return 0;
        return (tmp&1?-1:1)*cube((n/2/x)*2+1);
    };
    while(cin>>n,n){
        int ans=cube(n+1);
        for(int i=2;i<=n;++i) ans+=cal(i);
        cout<<"Crystal "<<++cnt<<": "<<ans<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
