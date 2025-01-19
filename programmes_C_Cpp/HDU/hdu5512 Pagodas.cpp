#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a,b,p,idx;
void solve(){
    cout<<"Case #"<<++idx<<": ";
    cin>>n>>a>>b;
    p=n/__gcd(a,b);
    cout<<(p&1?"Yuwgna\n":"Iaka\n");
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
