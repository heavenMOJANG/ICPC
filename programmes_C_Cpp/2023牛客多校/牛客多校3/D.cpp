#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll n,r[2010],c[2010],res,minr=LLONG_MAX,maxc;
char g[2010][2010];
void read(ll&n){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    n=x*f;
}
void write(ll n){
    if(n<0){putchar('-');n*=-1;}
    if(n>9) write(n/10);
    putchar(n%10+'0');
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    read(n);
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j) g[i][j]=getchar();
    for(ll i=1;i<=n;++i){
        ll cnt=0;
        for(ll j=1;j<=n;++j) if(g[i][j]=='1') cnt++;
        r[i]=max(cnt,n-cnt);
        res+=r[i];
    }
    for(ll j=1;j<=n;++j){
        ll cnt=0;
        for(ll i=1;i<=n;++i) if(g[i][j]=='1') cnt++;
        c[j]=max(cnt,n-cnt);
    }
    for(ll i=1;i<=n;++i) minr=min(minr,r[i]);
    for(ll i=1;i<=n;++i) maxc=max(maxc,c[i]);
    write(minr>maxc?res:-1);
    return 0;
}
