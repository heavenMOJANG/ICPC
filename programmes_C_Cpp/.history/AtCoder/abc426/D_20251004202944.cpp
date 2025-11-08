#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int l0 = s.find('0'), r0 = s.rfind('0'), l1 = s.find('1'), r1 = s.rfind('1');
    int ans0{}, ans1{};
    if (l1 != -1) ans0 = min(r1 + 1, n - l1);
    if (l0 != -1) ans1 = min(r0 + 1, n - l0);
    cout << min(ans0, ans1) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}