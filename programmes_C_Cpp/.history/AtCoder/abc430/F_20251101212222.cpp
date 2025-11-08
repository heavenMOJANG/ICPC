#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> sl(n + 1, 0), sr(n + 1, 0); 
    sl[n] = sr[n] = 0;
    for (int i = n - 1; i; -- i) {
        if (s[i - 1] == 'L') sl[i] = sl[i + 1] + 1;
        else sl[i] = 0;
        if (s[i - 1] == 'R') sr[i] = sr[i + 1] + 1;
        else sr[i] = 0;
    }
    vector<int> pl(n + 1, 0), pr(n + 1, 0);
    pl[1] = pr[1] = 0;
    for (int i = 2; i <= n; ++ i) {
        if (s[i - 2] == 'R') pl[i] = pl[i - 1] + 1;
        else pl[i] = 0;
        if (s[i - 2] == 'L') pr[i] = pr[i - 1] + 1;
        else pr[i] = 0;
    }
    vector<int> d(n + 2, 0);
    for (int i = 1; i <= n; ++ i) {
        int l = pl[i] + sl[i] + 1;
        int r = n - pr[i] - sr[i];
        if (l <= r) {
            d[l] ++;
            if (r + 1 <= n) d[r + 1] --;
        }
    }
    int C{};
    for (int i = 1; i <= n; ++ i) {
        C += d[i];
        cout << C << " \n"[i == n];
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}