#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
typedef __int128 ll;
using namespace std;
constexpr ll inf=0x7fffffff;
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
ll n,a[100010];
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f;
}
void write(ll x) {
    if(x>9) write(x/10);
    *O++=x%10+'0';
}
void solve(){
    n=read();
    ll sum=0,res=0;
    for(ll i=1;i<=n;++i) a[i]=read(),sum+=a[i];
    for(ll i=1;i<=n;++i) res+=a[i]*(sum-a[i]);
    write(res/2);puts("");
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;_=read();
    while(_--) solve();
    fwrite(obuf,O-obuf,1,stdout);
    return 0;
}
