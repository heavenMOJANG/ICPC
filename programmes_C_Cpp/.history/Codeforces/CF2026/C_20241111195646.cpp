#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    priority_queue<int> pq;
    int ans{}, cnt{};
    for (int i = 1; i <= n; ++ i) {
        ans += i;
        if (s[i] == '0') cnt ++;
        else {
            if (cnt) {
                ans -= i;
                pq.push(-i);
                cnt --;
            } else if (!pq.empty()) {
                ans -= i;
                ans += -pq.top();
                cnt ++;
                pq.pop();
                pq.push(-i);
            } else cnt ++;
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