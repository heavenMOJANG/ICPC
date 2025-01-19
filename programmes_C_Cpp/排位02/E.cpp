#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;
    while(cin>>n>>m&&n&&m){
        vector<int>d(n),k(m);
        for(int i=0;i<n;++i) cin>>d[i];
        for(int i=0;i<m;++i) cin>>k[i];
        sort(d.begin(),d.end());
        sort(k.begin(),k.end());
        int res=0,p=0;
        for(int i=0;i<m;++i){
            if(p==n) break;
            if(k[i]>=d[p]) res+=k[i],p++;
            else continue;
        }
        if(p<n) cout<<"Loowater is doomed!\n";
        else cout<<res<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
