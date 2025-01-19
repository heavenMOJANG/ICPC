#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef __int128 ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,res;
void read(ll&n){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    n=x*f;
}
void write(ll n){
    if(n<0){putchar('-');n*=-1;}
    static ll sta[256];
    ll top=0;
    do{sta[top++]=n%10,n/=10;}while(n);
    while(top) putchar(sta[--top]+48);
}
void solve(){
    read(n);
    if(n&1){
        ll k=5;
        while(k<=n){
            res+=(n/k+1)/2;
            k*=5;
        }
        n--;
    }
    ll k=5;
    while(k<=n){
        ll t=n/k;
        res+=t*(t-1)*(k/2)/2;
        res+=((t-1)/2*2)*((t+1)/2)/2;
        ll l=t*k,r=n;
        if(((l|r)&1)==0) r++;
        res+=t*(r-l+1)/2;
        k*=5;
    }
    write(res);
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}