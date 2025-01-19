#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    char ch;
    ll cnt=0;
    for(ll i=0;i<3;++i){
        cin>>ch;
        if(ch-'a'!=i) cnt++;
    }
    cout<<((cnt&1)?"NO\n":"YES\n");
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
