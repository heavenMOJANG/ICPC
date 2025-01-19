#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a[80010],res;
stack<ll>s;
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    s.push(a[1]);
    for(ll i=2;i<=n;++i){
        while(!s.empty()&&s.top()<=a[i]) s.pop();
		res+=s.size();
		s.push(a[i]); 
    }
    cout<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}