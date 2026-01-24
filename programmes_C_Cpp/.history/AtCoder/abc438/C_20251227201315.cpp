#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    stack<pair<int, int>> st;
    for (int i{}; i < n; ++ i) {
        int x; cin >> x;
        if (st.empty()) st.push({x, 1});
        else {
            if (st.top().first == x) st.top().second ++;
            else {
                if (st.top().second >= 4) {
                    st.pop();
                    if (!st.empty() && st.top().first == x) st.top().second ++;
                    else st.push({x, 1});
                }
            }
        }
    }
    if (!st.empty() && st.top().second >= 4) st.pop();
    int ans{};
    while (!st.empty()) {
        ans += st.top().second;
        st.pop();
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}