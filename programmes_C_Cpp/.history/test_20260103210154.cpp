#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
using namespace atcoder;

constexpr ll MOD = 998244353;

ll op(ll a, ll b){ return (a + b) % MOD; }
ll e(){ return 0; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin >> n)) return 0;
    vector<int> p(n);
    for(int i=0;i<n;i++){ cin >> p[i]; } // p is 1..n

    // 1) 计算 L[j] = # { i < j | p[i] < p[j] }
    segtree<ll, op, e> seg(n); // 下标 0..n-1 存放出现计数
    vector<ll> L(n,0), R(n,0);
    for(int j=0;j<n;j++){
        int x = p[j]-1; // 值域转为 0..n-1
        if(x > 0) L[j] = seg.prod(0, x); // 小于 x 的个数
        else L[j] = 0;
        seg.set(x, (seg.get(x) + 1) % MOD);
    }

    // 2) 计算 R[u] = # { v > u | p[v] < p[u] }
    seg = segtree<ll, op, e>(n); // 重建清零
    for(int u = n-1; u>=0; --u){
        int x = p[u]-1;
        if(x+1 < n) R[u] = seg.prod(x+1, n); // 大于 x 的后缀中比 x 小的个数
        else R[u] = 0;
        seg.set(x, (seg.get(x) + 1) % MOD);
    }

    // 3) 预处理 2^k 和 inv2^k
    vector<ll> pow2(n+5,1), inv2(n+5,1);
    ll inv_two = (MOD + 1) / 2; // 2^{-1} mod MOD
    for(int i=1;i<=n+2;i++){
        pow2[i] = (pow2[i-1] * 2) % MOD;
        inv2[i] = (inv2[i-1] * inv_two) % MOD;
    }

    // 4) 计算前缀 A[j] = L[j] * inv2^{j+1}, prefixA
    vector<ll> prefixA(n,0);
    for(int j=0;j<n;j++){
        ll Aj = (L[j] % MOD) * inv2[j+1] % MOD; // inv2^{j+1}
        if(j==0) prefixA[j] = Aj;
        else prefixA[j] = (prefixA[j-1] + Aj) % MOD;
    }

    // 5) 最终汇总：
    //    total = sum_{u=0..n-1} R[u] * ( L[u] + 2^{u} * sum_{j=0..u-1} L[j]*inv2^{j+1} )
    ll ans = 0;
    for(int u=0; u<n; ++u){
        ll leftSame = L[u] % MOD; // j == u contribution
        ll sumPrev = (u==0 ? 0 : prefixA[u-1]); // sum_{j=0..u-1} L[j]*inv2^{j+1}
        ll part = ( leftSame + (pow2[u] * sumPrev) % MOD ) % MOD;
        ans = ( ans + (R[u] % MOD) * part ) % MOD;
    }

    cout << ans % MOD << "\n";
    return 0;
}
