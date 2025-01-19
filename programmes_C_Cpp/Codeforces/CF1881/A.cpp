#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
string s1,s2;
void solve(){
    int n,m;cin>>n>>m;
    string s1,s2;cin>>s1>>s2;
    auto check=[&](string s1,string s2)->int
    {
        int l=s1.length();
        for(int i=0;i+m<=l; ++i) if(s1.substr(i,m)==s2) return 1;
        return 0;
    };
    if(check(s1,s2)){cout<<"0\n";return;}
    int res=-1,pos=0,l=2*max(n,m);
    while(n<l){
        s1=s1+s1;
        n<<=1;
        pos++;
        if(check(s1,s2)){res=pos;break;}
    }
    cout<<res<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
