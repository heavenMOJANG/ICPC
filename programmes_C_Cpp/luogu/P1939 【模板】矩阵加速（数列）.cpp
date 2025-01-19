#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll mod=1e9+7;
constexpr ll N=4;
struct matrix{
    ll m[N][N];
    friend matrix operator*(const matrix&a,const matrix&b){
        matrix c;
        memset(c.m,0,sizeof(c.m));
        for(ll i=0;i<N;++i)
            for(ll j=0;j<N;++j)
                for(ll k=0;k<N;++k) c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
        return c;
    }
    friend matrix pow_matrix(matrix a,ll n){
        matrix res;
        memset(res.m,0,sizeof(res.m));
        for(ll i=0;i<N;++i) res.m[i][i]=1;
        while(n){
            if(n&1) res=res*a;
            a=a*a;
            n>>=1;
        }
        return res;
    }
};
ll n;
void solve(){
    cin>>n;
    matrix a,b;
    a.m[1][1]=a.m[1][2]=a.m[1][3]=1;
    b.m[1][3]=b.m[2][1]=b.m[3][2]=b.m[3][3]=1;
    a=a*pow_matrix(b,n-1);
    cout<<a.m[1][1]<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}