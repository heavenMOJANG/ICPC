#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    int au{}, ag{}, cu{};
    string s; cin >> s;
    for (int i = 0; i < n; ++ i) {
        cin >> s;
        if (s == "Au") au ++;
        if (s == "Ag") ag ++;
        if (s == "Cu") cu ++;
    }
    cout << au + min(ag, cu) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}