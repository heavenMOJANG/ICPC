#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<vector<int>>g(n+1,vector<int>(m+1)),a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j) cin>>g[i][j];
    vector<string>s(n+1);
    for(int i=1;i<=n;++i) cin>>s[i],s[i]=" "+s[i];
    int cnt=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(s[i][j]=='1') cnt+=g[i][j];
            else cnt-=g[i][j];
    cnt=abs(cnt);
    if(!cnt){cout<<"YES\n";return;}
    map<int,int>mp;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            g[i][j]=(s[i][j]=='1'?1:-1);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
    function<int(int,int,int,int)> get=[&](int x1,int y1,int x2,int y2){
        return g[x2][y2]+g[x1-1][y1-1]-g[x1-1][y2]-g[x2][y1-1];
    };
    set<int>b;
    for(int i=k;i<=n;++i)
        for (int j=k;j<=m;++j){
            int res=get(i-k+1,j-k+1,i,j);
            b.insert(res);
        }
    int gcd=0;
    for(auto x:b) gcd=__gcd(gcd,x);
    if(!gcd){cout<<"NO\n";return;}
    if(cnt%gcd==0){cout<<"YES\n";return;}
    cout<<"NO\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}