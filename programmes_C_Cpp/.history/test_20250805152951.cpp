#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int add(int a, int b){ a+=b; if(a>=MOD) a-=MOD; return a; }
int subm(int a, int b){ a-=b; if(a<0) a+=MOD; return a; }
int mul(ll a, ll b){ return (int)(a*b%MOD); }
ll modexp(ll a, ll e=MOD-2){ ll r=1%MOD; a%=MOD; while(e){ if(e&1) r=r*a%MOD; a=a*a%MOD; e>>=1;} return r; }

static const int M = 17; // states 0..15 and 16 = L

using Mat = array<array<int,M>,M>;
Mat matMul(const Mat &A, const Mat &B){
    Mat C;
    for(int i=0;i<M;i++) for(int j=0;j<M;j++) C[i][j]=0;
    for(int i=0;i<M;i++){
        for(int k=0;k<M;k++) if(A[i][k]){
            ll aik = A[i][k];
            for(int j=0;j<M;j++) if(B[k][j]){
                C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Mat matPow(Mat A, ll e){
    Mat R;
    for(int i=0;i<M;i++) for(int j=0;j<M;j++) R[i][j] = (i==j);
    while(e){
        if(e&1) R = matMul(R,A);
        A = matMul(A,A);
        e >>= 1;
    }
    return R;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--){
        ll n; int k;
        cin>>n>>k;
        vector<int> D(k);
        for(int i=0;i<k;i++) cin>>D[i];
        // build transition matrix T
        Mat Tm;
        for(int i=0;i<M;i++) for(int j=0;j<M;j++) Tm[i][j]=0;
        int inv5 = modexp(5);
        int inv_k = modexp(k);
        int inv5k = mul(inv5, inv_k);
        int inv16 = modexp(16);
        // helper to add prob
        auto addTrans = [&](int u,int v,int coeff){ Tm[u][v] = add(Tm[u][v], coeff); };
        // transitions from states 0..15
        for(int u=0;u<16;u++){
            for(int d: D){
                // +
                ll y = u + d;
                addTrans(u, y<=15? (int)y:16, inv5k);
                // *
                y = u * d;
                addTrans(u, y<=15? (int)y:16, inv5k);
                // &
                addTrans(u, (u & d), inv5k);
                // |
                addTrans(u, (u | d), inv5k);
                // ^
                addTrans(u, (u ^ d), inv5k);
            }
        }
        // transitions from L
        for(int d: D){
            for(int x=0;x<16;x++){
                // +
                ll y = x + d;
                addTrans(16, y<=15? (int)y:16, mul(inv5k, inv16));
                // *
                y = x * d;
                addTrans(16, y<=15? (int)y:16, mul(inv5k, inv16));
                // &
                addTrans(16, (x & d), mul(inv5k, inv16));
                // |
                addTrans(16, (x | d), mul(inv5k, inv16));
                // ^
                addTrans(16, (x ^ d), mul(inv5k, inv16));
            }
        }
        
        // exponentiate Tm^(n-1)
        vector<int> pi1(M,0);
        for(int d: D) pi1[d] = add(pi1[d], inv_k);
        Mat Tn = (n==1? Tm : matPow(Tm, n-1));
        // final distribution
        vector<int> piN(M,0);
        for(int j=0;j<M;j++){
            ll s=0;
            for(int i=0;i<M;i++) if(pi1[i]) s = (s + (ll)pi1[i]*Tn[i][j])%MOD;
            piN[j] = (int)s;
        }
        
        // compute M = E[value | in L]
        // A_add, A_mul
        ll sumd=0;
        for(int d:D) sumd+=d;
        int A_add = mul(sumd%MOD, inv_k);
        int A_mul = A_add;
        // compute B_and, B_or, B_xor
        ll s_and=0, s_or=0, s_xor=0;
        for(int d:D){
            for(int x=0;x<16;x++){
                s_and += (x & d);
                s_or  += (x | d);
                s_xor += (x ^ d);
            }
        }
        ll denom16k = (16LL*k)%MOD;
        int inv16k = modexp(denom16k);
        int B_and = mul(s_and%MOD, inv16k);
        int B_or  = mul(s_or%MOD, inv16k);
        int B_xor = mul(s_xor%MOD, inv16k);
        int B = mul(add(add(B_and,B_or), B_xor), modexp(3));
        // solve M
        int two = 2, three=3;
        int inv5_ = inv5;
        int p1 = mul(mul(2, inv5_), A_add);
        int p2 = mul(mul(3, inv5_), B);
        int num = add(p1, p2);
        int t = mul(2, inv5_);
        int denom = subm(1, mul(t, add(1, A_mul)));
        int Mval = mul(num, modexp(denom));
        
        // expected value = sum_{u=0..15} u*piN[u] + Mval*piN[L]
        ll ans=0;
        for(int u=0;u<16;u++) ans = (ans + (ll)u * piN[u])%MOD;
        ans = (ans + (ll)Mval * piN[16])%MOD;
        cout<<ans<<"\n";
    }
    return 0;
}
