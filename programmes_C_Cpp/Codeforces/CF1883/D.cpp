#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct ddl{int l,r;};
struct ddr{int l,r;};
struct cmpl{bool operator()(const ddl&a,const ddl&b)const{return a.l>b.l;}};
struct cmpr{bool operator()(const ddr&a,const ddr&b)const{return a.r<b.r;}};
multiset<ddl,cmpl>ll;
multiset<ddr,cmpr>rr;
void solve(){
    int q;cin>>q;
    while(q--){
        string s;cin>>s;
        int l,r;cin>>l>>r;
        if(s[0]=='+'){
            ll.insert((ddl){l,r});
            rr.insert((ddr){l,r});
        }
        if(s[0]=='-'){
            ll.erase(ll.find((ddl){l,r}));
            rr.erase(rr.find((ddr){l,r}));
        }
        if((*ll.begin()).l>(*rr.begin()).r) cout<<"YES\n";
        else cout<<"NO\n"; 
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
