#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
//#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=998244353;
constexpr int N=1e6+10;
template<const int T>
struct ModInt{
   const static int mod=T;
    int x;
    ModInt(int x=0):x(x%mod){}
    ModInt(long long x):x(int(x % mod)){} 
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
mint fact[N],invfact[N];
void init(){
    fact[0]=invfact[0]=1;
    for(int i=1;i<N;++i) fact[i]=fact[i-1]*i;
    invfact[N]=fact[N-1].inv();
    for(int i=100010-2;i;--i) invfact[i]=invfact[i+1]*(i+1);
    return;
}
mint C(int a,int b){
    if(a<0||b<0||a<b) return 0;
    return fact[a]*invfact[b]*invfact[a-b];
}
void solve(){
    int n,q;cin>>n>>q;
    vector<array<int,2>>s(n+1);
    for(int i=1;i<=n;++i) cin>>s[i][0],s[i][0]+=s[i-1][0];
    for(int i=1;i<=n;++i) cin>>s[i][1],s[i][1]+=s[i-1][1];
    const int m=s[n][1];
    vector<mint>pre(m+1);
    for(int i=0;i<=m;++i) pre[i]=C(m,i);
    for(int i=1;i<=m;++i) pre[i]+=pre[i-1];
    auto get=[&](int l,int r){
        if(l>r) return mint(0);
        return pre[r]-(l>=1?pre[l-1]:0);
    };
    mint down=mint(2).pow(m).inv();
    while(q--){
        int l,r;cin>>l>>r;
        int b1=s[r][0]-s[l-1][0];
        int b2=s[n][0]-b1;
        int c1=s[r][1]-s[l-1][1];
        int c2=s[n][1]-c1;
        cout<<get(b2-b1+c2+1,m)*down<<" ";
    }
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int _=1;cin>>_;
    //while(_--)
    init();
    solve();
    return 0;
}
