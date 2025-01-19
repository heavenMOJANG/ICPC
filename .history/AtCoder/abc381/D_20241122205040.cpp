#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int cnt[200010];
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    int maxn{}, l{}, r{}, cnt{};
    unordered_map<int, int> mp;
    while (r < n) {
        int & num = mp[a[r]];
        num ++;
        if (num == 1) cnt ++;
        else if (num == 3) {
            cnt ++;
            while (l <= r && mp[a[l]] != 3) {
                mp[a[l]] --;
                if (mp[a[l]] == 1) cnt --;
                else if (mp[a[l]] == 0) mp.erase(a[l]);
            }
        }
    }
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}