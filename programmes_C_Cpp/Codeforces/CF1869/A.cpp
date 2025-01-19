#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a[110];
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    if(n&1)
        cout<<"4\n1 "<<n<<"\n1 "<<n-1<<"\n"<<n-1<<" "<<n<<"\n"<<n-1<<" "<<n<<"\n";
    else
        cout<<"2\n1 "<<n<<"\n1 "<<n<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
