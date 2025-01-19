#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int pow2[20]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144};
void solve(){
    int n,k;cin>>n>>k;
    bitset<32>b(k);
    int highBit=0;
    for(int i=31;i>=0;--i) if(b[i]==1){highBit=i;break;}
    vector<int>ans;
    auto qpow=[&](int x,int a){
        int res=1;
        while(x){
            if(x&1) res*=a;
            a*=a;
            x>>=1;
        }
        return res;
    };
    for(int i=0;i<=19;++i){
        if(i==highBit) continue;
        ans.emplace_back(pow2[i]);
    }

    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}