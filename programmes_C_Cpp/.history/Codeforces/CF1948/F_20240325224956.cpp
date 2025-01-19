#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=998244353;
template<const int T>
struct ModInt{
   const static int mod=T;
    int x;
    ModInt(int x=0):x(x%mod){}
    ModInt(int x):x(int(x % mod)){} 
    int val(){return x;}
    ModInt operator+(const ModInt&a)const{int x0=x+a.x;return ModInt(x0<mod?x0:x0-mod);}
    ModInt operator-(const ModInt&a)const{int x0=x-a.x;return ModInt(x0<0?x0+mod:x0);}
    ModInt operator*(const ModInt&a)const{return ModInt(1LL*x*a.x % mod);}
    ModInt operator /(const ModInt&a)const{return *this*a.inv();}
    bool operator==(const ModInt&a)const{return x==a.x;};
    bool operator!=(const ModInt&a)const{return x!=a.x;};
    void operator+=(const ModInt&a){x+=a.x;if(x>=mod) x-=mod;}
    void operator-=(const ModInt&a){x-=a.x;if(x<0) x+=mod;}
    void operator*=(const ModInt&a){x=1LL*x*a.x % mod;}
    void operator/=(const ModInt&a){*this=*this / a;}
    friend ModInt operator+(int y,const ModInt &a){int x0=y+a.x;return ModInt(x0<mod?x0:x0-mod);}
    friend ModInt operator-(int y,const ModInt &a){int x0=y-a.x;return ModInt(x0<0?x0+mod:x0);}
    friend ModInt operator*(int y,const ModInt &a){return ModInt(1LL*y*a.x % mod);}
    friend ModInt operator/(int y,const ModInt &a){return ModInt(y)/a;}
    friend ostream &operator<<(ostream &os,const ModInt &a){return os << a.x;}
    friend istream &operator>>(istream &is,ModInt &t){return is >> t.x;}
    ModInt pow(int64_t n)const{
        ModInt res(1),mul(x);
        while(n){
            if(n&1) res*=mul;
            mul*=mul;
            n>>=1;
        }
        return res;
    }
    ModInt inv()const{
        int a=x,b=mod,u=1,v=0;
        while(b){
            int t=a/b;
            a-=t*b;swap(a,b);
            u-=t*v;swap(u,v);
        }
        if(u<0) u+=mod;
        return u;
    }
    
};
using mint=ModInt<mod>;
mint fact[1000010],invfact[1000010];
void init(){
    fact[0]=invfact[0]=1;
    for(int i=1; i<1000010;++i) fact[i]=fact[i-1]*i;
    invfact[1000010]=fact[1000010-1].inv();
    for(int i=100010-2;i;--i) invfact[i]=invfact[i+1]*(i+1);
    return;
}
mint C(int a,int b){
    if (a<0||b<0||a<b) return 0;
    return fact[a]*invfact[b]*invfact[a-b];
}
void solve(){
    
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
