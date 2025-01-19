#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
const ll mod=1e9+7;
ll n,f[100010],s[5010],res;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
	for(ll i=1;i<=n;++i) cin>>f[i],s[f[i]]++;
	for(ll a=2;a<=5000;++a){
		for(ll c=1;c<=a/2;++c){ 
			ll d=a-c;
			if(c==d&&s[a]>=2&&s[c]>=2) res+=(s[a]*(s[a]-1)/2)*(s[c]*(s[c]-1)/2)%mod; 
			else if(c!=d&&s[a]>=2&&s[c]>=1&&s[d]>=1) res+=((s[a]*(s[a]-1))/2)*s[c]*s[d]%mod;
			res%=mod;
		}
	}
    cout<<res;
    return 0;
}