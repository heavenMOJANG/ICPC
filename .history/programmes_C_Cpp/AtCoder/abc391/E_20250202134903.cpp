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
    vector<int> cnt(4, 0);
    for (int i = 0; i < s.size(); i += 3) {
        int d = s[i] - '0' + s[i + 1] - '0' + s[i + 2] - '0';
        cnt[d] ++;
    }
    int ans{};
    if (cnt[0] + cnt[1] > cnt[2] + cnt[3]) {
        int d = cnt[0] + cnt[1] - cnt[2] - cnt[3] + 1;
        if (d) {
            int minn = min(d, cnt[1]);
            ans += minn;
            d -= minn;
        }
        if (d) {
            int minn = min(d, cnt[0]);
            ans += minn * 2;
            d -= minn;
        }
    } else {
        int d = cnt[2] + cnt[3] - cnt[0] - cnt[1];
        if (d) {
            int minn = min(d, cnt[2]);
            ans += minn;
            d -= minn;
        }
        if (d) {
            int minn = min(d, cnt[3]);
            ans += minn * 2;
            d -= minn;
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