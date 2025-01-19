#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define random(a,b) (rand()%(b-a+1))+a
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=1e9;
void solve(){
    cout<<(random(0ll,65536ll)<<15ll+random(0ll,65536ll))%mod<<"\n";
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    freopen("1.in","w",stdout);
    srand(time(NULL));
    int _=99999;
    cout<<"100000\n1\n";
    while(_--) solve();
    return 0;
}
