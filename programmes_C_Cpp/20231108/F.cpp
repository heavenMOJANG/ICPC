#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;
    while(cin>>n&&n){
        set<int>s;
        map<int,int>ind,oud;
        for(int i=0,u,v;i<n;++i){
            cin>>u>>v;
            ind[v]++;
            oud[u]++;
            s.insert(u);
            s.insert(v);
        }
        int flag=1;
        for(auto it=s.begin();it!=s.end();++it) if(ind[*it]!=oud[*it]){flag=0;break;}
        cout<<(flag?"YES\n":"NO\n");
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
