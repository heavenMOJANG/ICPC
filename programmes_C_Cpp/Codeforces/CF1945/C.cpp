#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    s=' '+s+' ';
    vector<int>f(n+2);
    for(int i=1;i<=n+1;++i) f[i]=f[i-1]+(s[i]-'0');
    int p=-1;
    for(int i=0;i<=n;++i){
        int l=i-f[i];
        int r=f[n]-f[i];
        if(l*2>=i&&r*2>=(n-i)){
            if(abs(2*i-n)<abs(2*p-n)) p=i;
        }
    }
    cout<<p<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
