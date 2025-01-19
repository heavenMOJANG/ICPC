#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=1e9+7;
int c[5010][5010];
void solve(){
    int n;cin>>n;
    int ans=1;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=2*i+1;++j){
            int tmp=j-i-1;
            int res=(j*c[min(j-1,n)][tmp])%mod;
            if(n-j<0){
                if(tmp!=i) res=0;
            }
            else{
                assert(n-j>=0&&i-tmp>=0);
                res=(res*c[n-j][i-tmp])%mod;
            }
            ans+=res;
        }
    cout<<ans<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<=5000;++i)
        for(int j=0;j<=i;++j){
            if(!j) c[i][j]=1;
            else c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}