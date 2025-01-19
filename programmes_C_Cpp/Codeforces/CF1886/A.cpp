#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    switch(n%3){
        case 0:{
            if(n>=12) cout<<"YES\n1 4 "<<n-5<<"\n";
            else cout<<"NO\n";
        }break;
        case 1:{
            if(n>=7) cout<<"YES\n1 4 "<<n-5<<"\n";
            else cout<<"NO\n";
        }break;
        case 2:{
            if(n>=8) cout<<"YES\n1 2 "<<n-3<<"\n";
            else cout<<"NO\n";
        }break;
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
