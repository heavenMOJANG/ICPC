#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    cout << s << "\n";
    return;
}
signed main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int _ = 1; cin >> _;
    while(_ --) solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}