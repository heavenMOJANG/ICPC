#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int prime[50000],vis[50000],idx;
void euler(int x){
    memset(vis,1,sizeof(vis));
    vis[1]=0;
    for(int i=2;i<=x;++i){
        if(vis[i]) prime[idx++]=i;
        for(int j=0;j<idx&&i*prime[j]<=x;++j){
            vis[i*prime[j]]=0;
            if(i%prime[j]==0) break;
        }
    }
}
void solve(){
    int n;
    while(cin>>n&&n){
        int nn=n,ans=1;
        for(int i=0;prime[i]*prime[i]<=n;++i){
            if(nn%prime[i]==0){
                int cnt=0;
                while(nn%prime[i]==0) nn/=prime[i],cnt++;
                ans=ans*(2*cnt+1);
            }
        }
        if(nn>1) ans*=3;
        cout<<n<<" "<<ans/2+1<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    euler(45000);
    while(_--) solve();
    return 0;
}
