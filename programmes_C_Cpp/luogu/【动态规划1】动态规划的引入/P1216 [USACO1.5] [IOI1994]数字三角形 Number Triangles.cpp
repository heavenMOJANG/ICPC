#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
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
ll n,a[1010][1010],maxn;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    read(n);
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=i;++j) read(a[i][j]);
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j) a[i][j]=max(a[i][j]+a[i-1][j],a[i][j]+a[i-1][j-1]);
    for(ll j=1;j<=n;++j) maxn=max(maxn,a[n][j]);
    write(maxn);
    return 0;
}
