#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll a,b,c;
void solve(){
    cin>>a>>b>>c;
    ll t1=(c&1?c/2+1:c/2),t2=c-t1;
    if(a+t1>b+t2) cout<<"First\n";
    else cout<<"Second\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}