#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;

using S = int;
constexpr int MOD = 998244353;

S op(S a, S b) { return (a + b) % MOD; }
S e() { return 0ll; }

int qpow(int a, int x) {
    int res = 1;
    while (x) {
        if (x & 1) res = res * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
}

void solve() {
    int n; 
    if (!(cin >> n)) return;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> p[i];

    if (n < 3) {
        cout << 0 << "\n";
        return;
    }

    // 预处理 2 的幂次和逆元
    vector<int> fac(n + 1, 1), inv(n + 1);
    for (int i = 1; i <= n; ++ i) fac[i] = fac[i - 1] * 2 % MOD;
    inv[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; ~i; -- i) inv[i] = inv[i + 1] * 2 % MOD;
    int inv2 = qpow(2, MOD - 2);

    // 1. 计算 L[i]: i 左边比 p[i] 小的个数
    segtree<S, op, e> tree_L(n + 1);
    vector<int> L(n + 1);
    for (int i = 1; i <= n; ++i) {
        L[i] = tree_L.prod(0, p[i]); // 查询 [0, p[i])
        tree_L.set(p[i], 1);         // 因为是排列，每个数只出现一次，直接设为 1 即可
    }

    // 2. 计算 R[i]: i 右边比 p[i] 小的个数
    segtree<S, op, e> tree_R(n + 1);
    vector<int> R(n + 1);
    for (int i = n; i >= 1; --i) {   // 倒序遍历
        R[i] = tree_R.prod(0, p[i]);
        tree_R.set(p[i], 1);
    }

    int ans = 0;
    int sum_term = 0; // 维护 sum_{i < j} (L[i] * 2^{-i})

    // 3. 统计答案
    for (int j = 1; j <= n; ++j) {
        // 情况 A: 长度 = 3 (此时 p[j] 既是第2个也是倒数第2个元素)
        // 形式: (S1, p[j], S3)
        int term_len3 = L[j] * R[j] % MOD;
        ans = (ans + term_len3) % MOD;

        // 情况 B: 长度 > 3 (p[j] 是倒数第2个元素，我们需要之前的某个 i 作为第2个元素)
        // 形式: (S1, p[i], ...中间..., p[j], Sk)
        // 公式贡献: R[j] * 2^(j - i - 1) * L[i]
        // 变形为: R[j] * 2^(j-1) * (L[i] * 2^(-i))
        
        if (j > 1) {
            // 计算当前 j 作为右端点的贡献
            int factor = R[j] * fac[j] % MOD * inv2 % MOD; // R[j] * 2^(j-1)
            int ways = factor * sum_term % MOD;
            ans = (ans + ways) % MOD;
        }

        // 将当前的 j 作为未来可能的 i 加入到 sum_term 中
        int current_i_val = L[j] * inv[j] % MOD;
        sum_term = (sum_term + current_i_val) % MOD;
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}