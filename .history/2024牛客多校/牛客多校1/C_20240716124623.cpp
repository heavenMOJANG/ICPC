#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=1e9+7;
constexpr int N=5e5+10;
int q;
stack<int>stk;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int sum=0;
    cin>>q;
    int p=0;
    while(q--){
        int t,v;cin>>t>>v;
        p-=t-1;
        sum=(sum+p*v%mod)%mod;
        cout<<sum<<"\n";
    }
    return 0;
}