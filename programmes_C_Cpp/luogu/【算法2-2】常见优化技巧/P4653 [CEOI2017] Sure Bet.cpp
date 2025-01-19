#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,v1[100010],v2[100010];
ld a[100010],b[100010],res;
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i]>>b[i];
    sort(a+1,a+1+n,greater<ld>());
    sort(b+1,b+1+n,greater<ld>());
    memset(v1,1,sizeof(v1));
    memset(v2,1,sizeof(v2));
    ld res1=0,res2=0;
    for(ll i=1,j=1;i<=n&&j<=n;){
		if(v1[i]) res1+=a[i];
		if(v2[j]) res2+=b[j];
		v1[i]=v2[j]=0;
		res=max(res,min(res1-i-j,res2-i-j));
		if(res1>=res2) j++;
		else i++;
	}
    cout<<fixed<<setprecision(4)<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
