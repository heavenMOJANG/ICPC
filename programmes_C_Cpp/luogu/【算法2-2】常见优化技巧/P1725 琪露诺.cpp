#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,l,r,a[200010],dp[200010];
deque<ll>q;
void solve(){
    cin>>n>>l>>r;
    for(ll i=0;i<=n;++i) cin>>a[i];
    for(ll i=n;i>=n-l;--i) dp[i]=a[i];
    q.push_back(n+1);
    for(ll i=n;i>= l;--i){
		while(q.size()&&dp[q.back()]<=dp[i]) q.pop_back();
		q.push_back(i);
		while(q.size()&&q.front()>i-l+r) q.pop_front();
		dp[i-l]=dp[q.front()]+a[i-l] ;
		
	}
    cout<<dp[0];
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
