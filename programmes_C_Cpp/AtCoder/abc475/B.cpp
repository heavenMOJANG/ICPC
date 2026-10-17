#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    int a1{}, a10{}, a100{};
    for (int i : views::iota(0, N)) {
        int A; cin >> A;
        if (A % 1000 == 0) continue;
        int k{A / 1000 + 1}, r{k * 1000 - A};
        a100 += r / 100; r %= 100;
        a10 += r / 10; r %= 10;
        a1 += r;
    }
    cout << a1 << " " << a10 << " " << a100 << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}