#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=1e5+10;
int n,a[N],dp[N][20],lg[N];
void init(){
    for(int i=1;i<=n;++i) dp[i][0]=a[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=1;i+(1<<j-1)<=n;++i) dp[i][j]=dp[i][j-1]|dp[i+(1<<j-1)][j-1];
}
int query(int l,int r){
    int k=lg[r-l+1];
    return dp[l][k]|dp[r-(1<<k)+1][k];
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    init();
    int l=0,r=n+1;
    while(l+1!=r){
        int mid=l+r>>1,cur=query(1,mid);
        int flag=1;
        for(int i=2;i+mid-1<=n;++i)
            if(query(i,i+mid-1)!=cur){flag=0;break;}
        if(flag) r=mid;
        else l=mid;
    }
    cout<<r<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=2;i<N;++i) lg[i]=lg[i>>1]+1;
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}