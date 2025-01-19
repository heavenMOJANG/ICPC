#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll N=2;
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
        matrix ans;
        memset(ans.m,0,sizeof(ans.m));
        for(ll i=0;i<N;++i) ans.m[i][i]=1;
        while(n--){
            if(n&1) ans=ans*a;
            a=a*a;
            n>>=1;
        }
        return ans;
    }
};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    return 0;
}