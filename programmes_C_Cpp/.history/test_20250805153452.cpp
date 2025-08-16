#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int add(int a, int b){ a+=b; if(a>=MOD) a-=MOD; return a; }
int subm(int a, int b){ a-=b; if(a<0) a+=MOD; return a; }
int mul(ll a, ll b){ return (int)(a*b%MOD); }
ll modexp(ll a, ll e=MOD-2){ ll r=1%MOD; a%=MOD; while(e){ if(e&1) r=r*a%MOD; a=a*a%MOD; e>>=1;} return r; }

// We use a 32-state Markov chain: state = (hi<<4) | lo, hi in {0,1}, lo in [0..15]
static const int M = 32;
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
        
        int inv5 = modexp(5);
        int invk = modexp(k);
        int prob = mul(inv5, invk); // each (op,d)
        
        // build 32x32 transition matrix
        Mat Tm;
        for(int i=0;i<M;i++) for(int j=0;j<M;j++) Tm[i][j]=0;
        for(int hi=0;hi<2;hi++){
            for(int lo=0;lo<16;lo++){
                int u = (hi<<4)|lo;
                for(int d: D){
                    // + d
                    {
                        int sum = lo + d;
                        int nhi = (hi==1 || sum>=16)?1:0;
                        int nlo = sum & 15;
                        int v = (nhi<<4)|nlo;
                        Tm[u][v] = add(Tm[u][v], prob);
                    }
                    // * d
                    {
                        int prod_hi = hi;
                        // if hi==1, u>=16 => u*d>=16
                        // else lo*d may overflow 16
                        int prod = lo * d;
                        int nhi = (hi==1 || prod>=16)?1:0;
                        int nlo = prod & 15;
                        int v = (nhi<<4)|nlo;
                        Tm[u][v] = add(Tm[u][v], prob);
                    }
                    // & d
                    {
                        // u & d: high bits drop
                        int andv = lo & d;
                        int nhi = 0;
                        int v = andv;
                        Tm[u][v] = add(Tm[u][v], prob);
                    }
                    // | d
                    {
                        // high bit preserved if hi==1
                        int hiv = hi;
                        int orv = lo | d;
                        int nhi = hiv;
                        int nlo = orv;
                        int v = (nhi<<4)|nlo;
                        Tm[u][v] = add(Tm[u][v], prob);
                    }
                    // ^ d
                    {
                        int hiv = hi;
                        int xorv = lo ^ d;
                        int nhi = hiv;
                        int nlo = xorv;
                        int v = (nhi<<4)|nlo;
                        Tm[u][v] = add(Tm[u][v], prob);
                    }
                }
            }
        }
        
        // exponentiate Tm to (n-1)
        Mat Tn = matPow(Tm, n-1);
        
        // initial distribution pi1
        vector<int> pi1(M,0);
        for(int d: D){
            int state = d; // hi=0, lo=d
            pi1[state] = add(pi1[state], invk);
        }
        
        // compute piN = pi1 * Tn
        vector<int> piN(M,0);
        for(int j=0;j<M;j++){
            ll s=0;
            for(int i=0;i<M;i++) if(pi1[i]) s = (s + (ll)pi1[i] * Tn[i][j]) % MOD;
            piN[j] = s;
        }
        
        // expected value = sum_{hi,lo} (hi*16 + lo)*piN
        ll ans = 0;
        for(int u=0;u<M;u++){
            int hi = u>>4;
            int lo = u & 15;
            int val = hi*16 + lo;
            ans = (ans + (ll)val * piN[u]) % MOD;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
