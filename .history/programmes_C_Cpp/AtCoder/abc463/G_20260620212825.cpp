#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
//期待値の線型性、及び座標の対称性により、E(|x'-X|) = E(x'-X)=X
//k歩移動したら、最後の座標はx'=k-(N-k)=2k-N。その確率はP=1/(2^N)*C(N,k)
//よって、期待値はE = 1/(2^N)*sigma{C(N,k)*|2k-N-X|}, k from 0 to N
//絶対値記号を消すため、式を二つの部分にする
//|2k-N-X|を見ると、自然的に「2k」と「N+X」の部分があります
//さらに「k」と「(N+X)/2」の関係を検討する
//「(N+X)/2」を「M」にして、k<=Mの時の式をA、k>Mの時の式をBと記す
//A-Bを見たら、なんとA-B=X*(2^N)ができた、これでB=A-X*(2^N)
//後でr*C(N,k)=N*C(N-1,k-1)やパスカルの三角を用いて、若干の変換をしたら、最終的な式はできる
//E=N/(2^[N-1])*C(N-1,M)-X+X/(2^[N-1])*sigma{C(N,i)}, i from 0 to M
//明らかに、式の前半はO(1)でありながら、後半はO(N)
//しかし、隣接する座標に移動するので、簡単なるF(n,m)の問題になった
//F(n,m+1)=F(n,m)+C(n,m+1)
//F(n,m-1)=F(n,m)-C(n,m)
//F(n+1,m)=2F(n,m)-C(n,m)
//F(n-1,m)=[F(n,m)+C(n-1,m)]/2
//ゆえにmo'sアルゴリズムで解決できる
constexpr int INF = 0x7fffffff;
constexpr int inv2 = 499122177;
constexpr int MOD = 998244353;
constexpr int MAXN = 2e5 + 10;
struct Query { int n, m, idx, x; };
int fac[MAXN]{1}, inv[MAXN]{1}, p2[MAXN]{1};
int qpow(int a, int x) {
    int res{1};
    a %= MOD;
    while (x) {
        if (x & 1) res = res * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
};
int C(int n, int m) {
    if (!~m || m > n) return 0ll;
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    for (int i{1}; i < MAXN; ++ i) {
        fac[i] = fac[i - 1] * i % MOD;
        p2[i] = p2[i - 1] * inv2 % MOD;
    }
    inv[MAXN - 1] = qpow(fac[MAXN - 1], MOD - 2);
    for (int i{MAXN - 2}; i; -- i) inv[i] = inv[i + 1] * (i + 1) % MOD;
    int T; cin >> T;
    vector<Query> query;
    vector<int> ans(T);
    for (int i{}; i < T; ++ i) {
        int N, X; cin >> N >> X;
        X = abs(X);
        if (X >= N) ans[i] = X % MOD;
        else {
            int M = (N + X) / 2;
            query.emplace_back(N, M, i, X);
        }
    }
    int b{max(1ll, (int)2e5 / (int)sqrt(max(1ll, (int)query.size())))};
    ranges::sort(query, [b](const Query& x, const Query& y) {
        int b1{x.n / b}, b2{y.n / b};
        if (b1 != b2) return b1 < b2;
        return b1 & 1 ? x.m > y.m : x.m < y.m;
    });
    int cur{1}, n{1}, m{0};
    auto addn = [&]() {
        cur = (cur * 2 % MOD - C(n, m) + MOD) % MOD;
        n ++;
    };
    auto addm = [&]() {
        m ++;
        (cur += C(n, m)) %= MOD;
    };
    auto deln = [&]() {
        cur = (cur + C(n - 1, m)) % MOD * inv2 % MOD;
        n --;
    };
    auto delm = [&]() {
        (cur += MOD - C(n, m)) %= MOD;
        m --;
    };
    for (const auto& q : query) {
        while (n < q.n) addn();
        while (m < q.m) addm();
        while (n > q.n) deln();
        while (m > q.m) delm();
        int N{q.n}, X{q.x};
        int t1{N * C(N - 1, q.m) % MOD * p2[N - 1] %  MOD};
        int t2{(MOD - X % MOD) % MOD};
        int t3{X % MOD * cur % MOD * p2[N - 1] % MOD};
        ans[q.idx] = (t1 + t2 + t3) % MOD;
    }
    for (int i{}; i < T; ++ i) cout << ans[i] << "\n"[i == T - 1];
    return 0;
}