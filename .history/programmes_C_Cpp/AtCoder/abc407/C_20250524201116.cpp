#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    reverse(s.begin(), s.end());
    int ans{};
    while (!s.empty()) {
        if (s[0] == '0') s.erase(0), ans ++;
        else {
            for (int i{}; i < s.size(); ++ i) {
                if (s[i] == '0') s[i] = '9';
                else s[i] --;
            }
            ans ++;
        }
        cout << s << "\n";
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}