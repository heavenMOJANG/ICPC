#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,m,a[500010],s[500010],res;
deque<ll>q;
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;++i){
        cin>>a[i],s[i]=s[i-1]+a[i];
        while(!q.empty()&&q.front()<i-m) q.pop_front();
        while(!q.empty()&&s[i-1]<s[q.back()]) q.pop_back();
        q.push_back(i-1);
        if(!q.empty()) res=max(res,s[i]-s[q.front()]);
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
