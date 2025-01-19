#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    string a,b;cin>>a>>b;
    int maxn=0;
    for(int i=0;i<b.size();++i){
        int idx=i,cnt=0;
        for(int j=0;j<a.size();++j)
            if(a[j]==b[idx]) idx++,cnt++;
        maxn=max(maxn,cnt);
    }
    cout<<a.size()+b.size()-maxn<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}