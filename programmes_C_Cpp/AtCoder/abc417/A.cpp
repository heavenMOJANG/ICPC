#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    while (b --) s.pop_back();
    reverse(s.begin(), s.end());
    while (a --) s.pop_back();
    reverse(s.begin(), s.end());
    cout << s << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}