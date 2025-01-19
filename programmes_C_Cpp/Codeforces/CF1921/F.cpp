#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n,q,s,d,k;
int a[100010],pre[2][350][100010];
void init(){
    for(int i=1;i<=n&&i<=333;++i){
        for(int j=1;j<=n;++j){
            pre[0][i][j]=a[j];
            pre[1][i][j]=((j-1)/i+1)*a[j];
            if(j>i){
                pre[0][i][j]+=pre[0][i][j-i];
                pre[1][i][j]+=pre[1][i][j-i];
            }
        }
    }
}
int query_1(){
    int ans=pre[1][d][s+(k-1)*d]-pre[1][d][max(0ll,s-d)];
    int sub=(s-1)/d*(pre[0][d][s+(k-1)*d]-pre[0][d][max(0ll,s-d)]);
    return ans-sub;
}
int query_2(){
    int res=0;
    for(int i=0;i<k;++i) res+=(i+1)*a[i*d+s];
    return res;
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>a[i];
    init();
    while (q--) {
        cin>>s>>d>>k;
        if(d<=333)cout<<query_1();
        else cout<<query_2();
        if(q==0) cout<<"\n";
        else cout<<" ";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
