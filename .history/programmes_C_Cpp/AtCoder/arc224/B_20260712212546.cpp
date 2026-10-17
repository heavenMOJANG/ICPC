#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int sq(int x) {
    int l{}, r{(int)2e9};
    while (l < r) {
        int mid{l + (r - l) / 2};
        if (mid * mid >= x) r = mid;
        else l = mid + 1;
    }
}
void solve() {
    int N; cin >> N;
    int up{sq(4 * N)};
    cout << 2 * N - up << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}