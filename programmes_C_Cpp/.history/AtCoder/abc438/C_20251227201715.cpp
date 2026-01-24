#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> st;
    for (int i{}; i < n; ++ i) {
        int x; cin >> x;
        if (!st.empty() && st.back().first == x) st.back().second ++;
        else st.emplace_back(x, 1);
        while (!st.empty() && st.back().second >= 4) {
            st.back().second -= 4;
            if (!st.back().second) st.pop_back();
            else break;
            if (st.size() >= 2 && st.back().first == st[st.size() - 2].first) {
                st[st.size()-2].second += st.back().second;
                st.pop_back();
            }
        }
    }
    int ans{};
    while (!st.empty()) {
        ans += st.back().second;
        st.pop_back();
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