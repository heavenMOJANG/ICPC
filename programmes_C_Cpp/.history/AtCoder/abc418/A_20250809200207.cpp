#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    if (s.size() < 3) { cout << "No\n"; return; }
    int n = s.size();
    if (s.substr(n - 3, n) != "tea") cout << "No\n";
    else cout << "Yes\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}