#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> vis(n + 1, 0);
    int ans = 0;
    vector<int> r1, r2, r3;
    for (int i = 1; i <= n; ++ i) {
        int len = 0, x = i;
        while (!vis[x]) {
            vis[x] = 1;
            x = a[x];
            len ++;
        }
        if (len > 1) {
            if (len % 4 == 0) ans += len / 4;
            if (len % 4 == 3) r3.emplace_back(len);
            if (len % 4 == 2) r2.emplace_back(len);
            if (len % 4 == 1) r1.emplace_back(len);
        }  
    }
    sort(r1.begin(), r1.end());
    sort(r2.begin(), r2.end());
    sort(r3.begin(), r3.end());
    while (!r3.empty()) {
        if (!r1.empty()) {
            int sum = r3.back(); r3.pop_back();
            sum += r1.back(); r1.pop_back();
            ans += sum / 4;
        } else {
            int sum = accumulate(r3.begin(), r3.end(), 0);
            r3.clear();
            ans += (sum + 3) / 4;
        } 
    }
    while (!r2.empty()) {
        if (r1.size() >= 2) {
            int sum = r2.back(); r2.pop_back();
            sum += r1.back(); r1.pop_back();
            sum += r1.back(); r1.pop_back();
            ans += (sum + 3) / 4;
        }
    }
    ans += (accumulate(r1.begin(), r1.end(), 0) + 3) / 4;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}