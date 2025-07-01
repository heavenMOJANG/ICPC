#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
typedef long long ll;
using namespace std;
const ll inf=0x7fffffff;
const ll mod=1e9+7;
ll _,n,m,d[1000010],sum[1000010],fac[1000010],infac[1000010];
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
ll read(){
	ll x=0,f=1;
    char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f;
}
void write(ll x){
    if(x>9) write(x/10);
    *O++=x%10+'0';
}
ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
ll C(ll a,ll b){return fac[a]*infac[b]%mod*infac[a-b]%mod;}
void solve(){
    n=read();m=read();
    for(ll i=0;i<=n;++i) d[i]=0,sum[i]=0;
	fac[0]=infac[0]=1;
	for(ll i=1;i<1e6+10;++i) {
	    fac[i]=fac[i-1]*i%mod;
	    infac[i]=infac[i-1]*qpow(i,mod-2)%mod;
	}
    for(ll i=0,u,v;i<m;++i){
		u=read();v=read();
		d[u]++;d[v]++;
	}
	for(ll i=1;i<=n;++i)
		for(ll k=2;k<=d[i];++k) sum[k]=((sum[k]+C(d[i],k))%mod+mod)%mod;
	ll ans=sum[2];
	for(ll i=3;i<=n-1;i++) ans^=sum[i];
	write(ans);
	puts("");
	return;
}
signed main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    _=read();
    while(_--) solve();
    fwrite(obuf,O-obuf,1,stdout);
    return 0;
}
