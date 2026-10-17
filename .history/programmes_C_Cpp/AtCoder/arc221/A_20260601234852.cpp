#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
    int dlt = abs(B * C - A * D);
    if (dlt == 0) {
        int g = __gcd(A, C), k = B * g / A;
        int gm = g % MOD, km = k % MOD, Nm = N % MOD;
        int inv2 = 499122177;
        int t1 = gm * Nm % MOD * (Nm + 1) % MOD * inv2 % MOD;
        int t2 = km * Nm % MOD;
        int ans = (t1 + t2) % MOD;
        cout << ans << "\n";
        return;
    }
    vector<int> divs;
    for (int i = 1; i * i <= dlt; ++ i)
        if (dlt % i == 0) {
            divs.emplace_back(i);
            if (i * i != dlt) divs.emplace_back(dlt / i);
        }
    sort(divs.begin(), divs.end(), greater<int>());
    vector<int> f(divs.size());
    int ans{};
    auto exgcd = [&](int a, int b, int& x, int& y) -> int {
        int x0{1}, y0{}, x1{}, y1{1};
        while (b != 0) {
            int q = a / b, r = a % b;
            int x2 = x0 - q * x1, y2 = y0 - q * y1;
            x0 = x1, y0 = y1, x1 = x2, y1 = y2;
        }
        x = x0, y = y0;
        return a;
    };
    auto get = [&](int A, int B, int M) -> pair<int, int> {
        int x, y;
        int g = exgcd(A, M, x, y);
        if (B % g != 0) return {-1, -1};
        int Mp = M / g, x0 = (x % Mp + Mp) % Mp, Bp = B / g % Mp;
        x0 = x0 * Bp % Mp;
        return {x0, Mp};
    };
    auto CRT = [&](int x1, int m1, int x2, int m2) -> pair<int, int> {
        int B = ((x2 - x1) %  m2 + m2) % m2;
        auto [k, m2p] = get(m1, B, m2);
        if (k == -1) return {-1, -1};
        int L = m1 * m2p, X = (x1 + m1 * k) % L;
        return {X, L};
    };
    for (int i{}; i < divs.size(); ++ i) {
        int d = divs[i];
        int Bm = ((-B % d) + d) % d;
        auto [x1, m1] = get(A, Bm, d);
        int Dm = ((-D % d) + d) % d;
        auto [x2, m2] = get(C, Dm, d);
        int cd{};
        if (x1 != -1 && x2 != -1) {
            auto [X, L] = CRT(x1, m1, x2, m2);
            if (X != -1) {
               if (X == 0) cd = N / L;
               else {
                if (N >= X) cd = (N - X) / L;
                else cd = 0;
               }
            }
        }
        f[i] = cd;
        for (int j{}; j < i; ++ j) if (divs[i] % d == 0) f[i] -= f[j];
        int cnt = f[i] % MOD;
        if (cnt < 0) cnt += MOD;
        int t = d % MOD * cnt % MOD;
        (ans += t) %= MOD;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}
