#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,a[60],res=1;
int main(int argc,const char*argv[]){
	cin>>n;
	for(ll i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;++i) res=res*(a[i]-i+1)%1000000007;
	printf("%lld",res);
    return 0;
}