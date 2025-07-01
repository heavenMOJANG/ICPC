#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    for (int i{}; i < n; ++ i) {
        string s; cin >> s;
        for (int j{}; j < s.size(); ++ j) {
            if (s[j] == '1' || s[j] == 'i' || s[j] == 'l' || s[j] == 'I') continue;
            cout << s[j];
        }
        cout << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}