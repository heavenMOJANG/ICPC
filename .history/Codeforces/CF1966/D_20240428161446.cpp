#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    bitset<32>b(k);
    int highBit=0;
    for(int i=31;i>=0;--i) if(b[i]==1){highBit=i;break;}
    vector<int>ans;
    for(int i=0;i<=19;++i){
        if(i==highBit) continue;
        ans.emplace_back(pow[i]);
    }
    ans.emplace_back(k-pow[highBit]);
    ans.emplace_back(k+1+pow[highBit]);
    ans.emplace_back(k+1);
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();++i) cout<<ans[i]<<" \n"[i==ans.size()-1];
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}