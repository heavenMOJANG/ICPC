#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n,k;
    cin>>n>>k;
    ll res=0,x;
    for(ll i=1;i+k-1<=n;i+=k){
        cout<<"? "<<i<<endl;
        cin>>x;
        res^=x;
    }
    ll m=n%k;
    if(m){
        ll p1=n-m/2-k+1,p2=n-k+1;
        cout<<"? "<<p1<<endl;
        cin>>x;
        res^=x;
        cout<<"? "<<p2<<endl;
        cin>>x;
        res^=x;
    }
    cout<<"! "<<res<<endl;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
