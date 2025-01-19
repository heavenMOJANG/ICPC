#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=1e9+7;
struct Node{
    int len,l,r,cnt;
    Node operator+(const Node&x){
        Node res;
        res.len=len+x.len;
        res.l=len==l?x.l+l:l;
        res.r=x.len==x.r?r+x.r:x.r;
        res.cnt=(cnt+x.cnt+(r%mod)*(x.l%mod)%mod)%mod;
        return res;
    }
}dp[70][70];
Node get(int n,int k){
    if(k>=0) return dp[n][k];
    return {1ll<<n,0,0,0};
}
void solve(){
    int n,k;cin>>n>>k;
    Node tmp={0,0,0,0};
    int s=0;
    for(int i=60;i>=0;--i)
        if(n>>i&1){
            tmp=tmp+get(i,k-s);
            s++;
        }
    cout<<tmp.cnt<<"\n";
}
#undef int
int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<=60;++i) dp[0][i]={1,1,1,1};
    for(int i=1;i<=60;++i)
        for(int j=0;j<=60;++j) dp[i][j]=get(i-1,j)+get(i-1,j-1);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}