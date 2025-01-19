#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
//#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int a[128000010];
void solve(){
    int n,s;cin>>n>>s;
    auto cal=[&](int x,int y){return x*x+y;};
    for(int i=1,x,y,len;i<=n;++i){
        cin>>x>>y>>len;
        for(int j=0;j<len;++j){
            a[cal(x+y+j,y*2)]++;
            if(x) a[cal(x+y+j,(y+j)*2+1)]--;
        }
    }
    int ans=0;
    for(int i=0;i<s;++i){
        int pre=0;
        for(int j=0;j<2*i+1;++j){
            pre+=a[cal(i,j)];
            if(pre) ans++;
        }
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
