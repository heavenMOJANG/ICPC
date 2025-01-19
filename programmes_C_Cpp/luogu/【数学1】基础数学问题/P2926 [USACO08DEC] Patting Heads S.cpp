#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,a[100010],b[100010],cnt[1000010],ans[1000010];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=0;i<n;++i) cin>>a[i],b[i]=a[i],cnt[a[i]]++;
    sort(b,b+n);
	ll len=unique(b,b+n)-b;
	for(ll i=0;i<len;++i)
		for(ll j=1;b[i]*j<=b[len-1];++j) ans[b[i]*j]+=cnt[b[i]];
	for(ll i=0;i<n;++i) cout<<ans[a[i]]-1<<'\n';
    return 0;
}