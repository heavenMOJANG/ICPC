#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string S; cin >> S;
    stack<int> stk;
    int ans{};
    for (char c : S) {
        if (c == 'A') stk.emplace(1);
        else if (c == 'B') {
            bool ok{};
            while (!stk.empty()) {
                int x{stk.top()}; stk.pop();
                if (x == 1) { ok = true; break; }
            }
            if (ok) stk.emplace(2);
            else ans ++;
        } else if (c == 'C') {
            bool ok{};
            while (!stk.empty()) {
                int x{stk.top()}; stk.pop();
                if (x == 2) { ok == true; break; }
            }
            if (ok) {}
            else ans ++;
        }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}