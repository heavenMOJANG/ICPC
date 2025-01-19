#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
__int128 a[100010],b[100010],x,y;
ll n;
__int128 gcd(__int128 a,__int128 b){return b==0?a:gcd(b,a%b);}
__int128 exgcd(__int128 a,__int128 b,__int128&x,__int128&y){
    if(b==0){x=1,y=0;return a;}
    __int128 res=exgcd(b,a%b,x,y),tmp;
    tmp=x;x=y;y=tmp-(a/b)*y;
    return res;
}
__int128 inv(__int128 a,__int128 b) {
    __int128 res=exgcd(a,b,x,y);
    while(x<0) x+=b;
    return x;
}
inline void readln(__int128 &n){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    n=x*f;
}
inline void writeln(__int128 n){
    if(n<0){
        putchar('-');
        n*=-1;
    }
    if(n>9) writeln(n/10);
    putchar(n % 10 + '0');
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) readln(a[i]),readln(b[i]);
    for(ll i=2;i<=n;++i) {
            __int128 a1=a[i-1],a2=a[i],b2=b[i],b1=b[i-1],t=gcd(a1,a2);
            a[i]=(a1*a2)/t;
            b[i]=(inv(a1/t,a2/t)*(b2-b1)/t)%(a2/t)*a1+b1;
            b[i]=(b[i]%a[i]+a[i])%a[i];
        }
    writeln(b[n]);
    return 0;
}