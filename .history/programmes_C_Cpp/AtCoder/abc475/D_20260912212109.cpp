#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string S; cin >> S;
    int N{(int)S.size()};
    int pw{1};
    for (int i : views::iota(0, N)) pw *= 10;
    int upp{pw - 1}, low{N == 1 ? 2 : pw / 10};
    //euler
    vector<int> is(upp + 1, 0), primes;
    for (int i : views::iota(2, upp + 1)) {
        if (!is[i]) primes.emplace_back(i);
        for (int p : primes) {
            if (i * p > upp) break;
            is[i * p] = 1;
            if (i % p == 0) break;
        }
    }
    auto check = [&](int x) {
        string T{to_string(x)};
        array<int, 26> c2d;
        array<int, 10> d2c;
        c2d.fill(-1); d2c.fill(-1);
        for (int i : views::iota(0, N)) {
            int c{S[i] - 'a'}, d{T[i] - '0'};
            if (c2d[c] != -1 && c2d[c] != d) return false;
            if (d2c[d] != -1 && d2c[d] != c) return false;
            c2d[c] = d; d2c[d] = c;
        }
        return true;
    };
    for (int p : primes) {
        if (p < low) continue;
        if (p > upp) break;
        if (check(p)) { cout << p << "\n"; return; }
    }
    cout << "-1\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}