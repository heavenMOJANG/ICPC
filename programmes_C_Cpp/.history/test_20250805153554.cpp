#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

// 快速模运算工具
int add(int a,int b){ a+=b; if(a>=MOD) a-=MOD; return a; }
int subm(int a,int b){ a-=b; if(a<0) a+=MOD; return a; }
int mul(ll a,ll b){ return int(a*b%MOD); }
ll modexp(ll a,ll e=MOD-2){
    ll r=1; a%=MOD;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD;
        e>>=1;
    }
    return r;
}

static const int S = 17;  // 0..15 plus 16='L'
using Mat = array<array<int,S>,S>;

// 矩阵乘法
Mat mulMat(const Mat &A, const Mat &B){
    Mat C;
    for(int i=0;i<S;i++) for(int j=0;j<S;j++) C[i][j]=0;
    for(int i=0;i<S;i++){
        for(int k=0;k<S;k++) if(A[i][k]){
            ll aik=A[i][k];
            for(int j=0;j<S;j++) if(B[k][j]){
                C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// 矩阵快速幂
Mat powMat(Mat A, ll e){
    Mat R;
    for(int i=0;i<S;i++) for(int j=0;j<S;j++) R[i][j]=(i==j);
    while(e){
        if(e&1) R=mulMat(R,A);
        A=mulMat(A,A);
        e>>=1;
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

        // 基础概率 1/(5*k)
        int inv5 = modexp(5), invk = modexp(k);
        int P = mul(inv5, invk);

        // 构造 17x17 转移矩阵
        Mat Tm;
        for(int i=0;i<S;i++) for(int j=0;j<S;j++) Tm[i][j]=0;

        auto trans = [&](int u, ll val){
            int v = (val<=15 ? int(val) : 16);
            Tm[u][v] = add(Tm[u][v], P);
        };

        // 状态 0..15
        for(int u=0;u<16;u++){
            for(int d: D){
                trans(u, u + d);
                trans(u, 1LL*u * d);
                trans(u, u & d);
                trans(u, u | d);
                trans(u, u ^ d);
            }
        }
        // “L” 状态也同理：把它看作任意大值，当你对它加/乘/按位时
        // 实际数值 >=16，转移仍按上式，只是 u=16 带入运算
        for(int d: D){
            // +、*：结果 ≥16
            auto goL = [&](ll val){
                // 任何 val>=16 都映回 “L”
                Tm[16][16] = add(Tm[16][16], P);
            };
            // 加法
            goL(0);
            // 乘法
            goL(0);
            // 按位运算：任意大值 &/|/^ d 都 ≤15 可能落回 0..15
            for(int op=0;op<3;op++){
                // 枚举大值的所有低4位可能 0..15
                for(int lo=0;lo<16;lo++){
                    int res = (op==0 ? (lo & d)
                              : op==1 ? (lo | d)
                                       : (lo ^ d));
                    Tm[16][res] = add(Tm[16][res], mul(P, modexp(16)));
                }
            }
        }

        // 计算 T^(n-1)
        Mat Tn = (n==1 ? Tm : powMat(Tm, n-1));

        // 初始分布 π1
        vector<int> pi1(S,0);
        for(int d: D){
            pi1[d] = add(pi1[d], invk);
        }

        // πN = π1 × Tn
        vector<int> piN(S,0);
        for(int j=0;j<S;j++){
            ll sum=0;
            for(int i=0;i<S;i++){
                sum += (ll)pi1[i]*Tn[i][j];
            }
            piN[j] = int(sum % MOD);
        }

        // 还需要求 “L” 状态的条件期望 E_L：
        // 当你在 L 上，下一次：
        //  - 以 2/5 概率 做 +/×，结果还是 L；
        //  - 以 3/5 概率 做 &/|/^，落到 0..15 均匀分布，
        //    然后再继续下去。可以解一元一次得到 E_L。
        //
        // 设 E_L = (2/5)*(E_L + A) + (3/5)*(B)
        //  其中 A = E[新算 +/× 中的具体值偏移]，B = E[按位落回 0..15 的平均值]
        ll sumd = 0;
        for(int d: D) sumd += d;
        int A = mul(sumd%MOD, invk);     // E[d] for +，乘法也是 same since E[lo*d|lo>=?] 我们仅做近似
        // 精确计算 B：
        ll s_and=0, s_or=0, s_xor=0;
        for(int lo=0;lo<16;lo++){
            for(int d: D){
                s_and += (lo & d);
                s_or  += (lo | d);
                s_xor += (lo ^ d);
            }
        }
        ll inv16k = modexp((ll)16*k % MOD);
        int Band = mul(s_and%MOD, inv16k);
        int Bor  = mul(s_or %MOD, inv16k);
        int Bxor = mul(s_xor%MOD, inv16k);
        int B = mul(add(Band, add(Bor, Bxor)), modexp(3));  // avg of three bitwise ops

        // E_L = [ (2/5)*A + (3/5)*B ] / [ 1 - (2/5) ]
        int two5 = mul(2, modexp(5));
        int three5 = mul(3, modexp(5));
        int num = add(mul(two5, A), mul(three5, B));
        int den = subm(1, two5);
        int EL = mul(num, modexp(den));

        // 最终期望 = sum_{u=0..15} u*pi + E_L * pi[L]
        ll ans = 0;
        for(int u=0;u<16;u++) ans = (ans + (ll)u * piN[u])%MOD;
        ans = (ans + (ll)EL * piN[16]) % MOD;

        cout << ans << "\n";
    }
    return 0;
}
