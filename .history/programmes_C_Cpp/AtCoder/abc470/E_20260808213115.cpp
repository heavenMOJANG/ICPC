#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, L; cin >> N >> L;
    long double ans{};
    for (int i : views::iota(0, N)) {
        int x; cin >> x;
        ans += x;
    }
    vector dp(210, vector<vector<long double>> (210, vector<long double>(210, 0)));
    for (int l : views::iota(1, L + 1)) {
        int x; cin >> x;
        ans += x;
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}