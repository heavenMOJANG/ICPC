#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    map<string, int> mp;
    while (N --) {
        string S; cin >> S;
        transform(S.begin(), S.end(), S.begin(), ::tolower);
        mp[S]++;
    }
    int ans{};
    for (auto [key, value] : mp) ans = max(ans, value);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}