#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
constexpr int ROOT = 3;
int qpow(int a, int x) {
    int res = 1;
    while(x) {
        if (x & 1) res = res * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
}
void ntt(vector<int>& a, bool opt) {
    int n{(int)a.size()};
    for (int i{1}, j{}; i < n; ++ i) {
        int bit{n >> 1};
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int m{2}; m <= n; m <<= 1) {
        int wlen{qpow(opt ? 332748118 : ROOT, (MOD - 1) / m)};
        for (int i{}; i < n; i += m) {
            int w{1};
            for (int j : views::iota(0, m / 2)) {
                int u{a[i + j]}, v{a[i + j + m / 2] * w % MOD};
                a[i + j] = (u + v) % MOD;
                a[i + j + m / 2] = (u - v + MOD) % MOD;
                (w *= wlen) %= MOD;
            }
        }
    }
    if (opt) {
        int invN{qpow(n, MOD - 2)};
        for (int& x : a) (x *= invN) %= MOD;
    }
}
bool check(const vector<int>& in, int n) {
    int m{1};
    while (m < 2 * n - 1) m <<= 1;
    vector<int> c(m);
    copy(in.begin(), in.end(), c.begin());
    ntt(c, false);
    for (int& x : c) x = x * x % MOD;
    ntt(c, true);
    for (int z : views::iota(1, n)) {
        if (!in[z]) continue;
        int s{n - z}, ways{c[s]};
        if (s % 2 == 0 && in[s / 2]) ways --;
        int t{n - 2 * z};
        if (t >= 1 && t < n && t != z && in[t]) ways -= 2;
        if (ways > 0) return true;
    }
    return false;
}
bool ask(int x) {
    cout << "? " << x << endl;
    string s;
    if (!(cin >> s) || s == "-1") exit(0);
    return s == "Yes";
}
void solve() {
    int N; cin >> N;
    vector<int> in(N, 0);
    if (N % 2 == 0) {
        if (!ask(N / 2)) { cout << "! 2" << endl; return; }
        in[N / 2] = 1;
    }
    int P{(N - 1) / 2};
    vector<int> y, n;
    for (int x : views::iota(1, P + 1)) {
        in[x] = ask(x);
        if (in[x]) y.emplace_back(x);
        else n.emplace_back(x); 
    }
    for (int x : (y.size() <= n.size() ? y : n))
        if (ask(N - x) == in[x]) { cout << "! 2" << endl; return; }
    for (int x : views::iota(1, P + 1)) (ask(x) ? y : n).emplace_back(x);
    cout << "! " << (check(in, N) ? 3 : -1) << endl;
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}