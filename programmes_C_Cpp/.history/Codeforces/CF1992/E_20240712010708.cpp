#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    string s=to_string(n),t;
    function<int(int,int)> check=[&](int a,int b){
        if(a>10000||b>10000||b>a*n) return 0;
        int res=n*a-b;
        int len=s.size()*a-b;
        if(!len) return 0;
        if(len>to_string(res).size()) return 0;
        string st;
        for(int i=0;i<len;++i) st+=s[i%s.size()];
        return int(stoi(st)==res);
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;//cin>>_;
    while(_--) solve();
    return 0;
}