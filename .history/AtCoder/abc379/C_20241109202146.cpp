#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> x(n + 1), a(n + 1, 0);
    stack<pair<int, int>> st;
    for (int i = 0; i < m; ++ i) cin >> x[i];
    for (int i = 0; i < m; ++ i) cin >> a[x[i]], st.push({x[i], a[x[i]]});
    int ans{};
    for (int i = n; i >= 1; -- i) {
        cout << i << " " << st.top().first << " " << st.top().second << "\n";
        if (!a[i]) {
            if (st.empty()) { cout << "-1\n"; return; }
            if (st.top().first > i) { cout << "-1\n"; return; }
            else {
                if (st.top().second > 2) st.top().second --;
                else {
                    a[st.top().first] = 0;
                    st.pop();
                }
                ans += i - st.top().first;
            }
        } else {
            if (st.empty()) continue;
            while (!st.empty() && st.top().first >= i) st.pop();
        }
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