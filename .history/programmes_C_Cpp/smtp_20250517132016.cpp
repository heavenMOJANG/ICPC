#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string a, b; cin >> a >> b;
    if (a.size() > b.size()) swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = a.size(); i < b.size(); ++ i) a += "0";
    string s{};
    for (int i{}; i < a.size(); ++ i) {
        int d = (a[i] - '0' + b[i] - '0') % 10;
        s += char(d + '0');
    }
    reverse(s.begin(), s.end());
    int ans = stoi(s);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}