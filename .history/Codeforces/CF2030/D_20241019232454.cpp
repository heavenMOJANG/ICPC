#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; ++ i) cin >> p[i];
    string s; cin >> s;
    int lenL{}, lenR{}, l = n - 1, r{};
    for (int i = 0; i < n; ++ i)
        if (s[i] == 'R') lenR ++, r = i;
        else break;
    for (int i = n - 1; i >= 0; -- i)
        if (s[i] == 'L') lenL ++, l = i;
        else break;
    while (q --) {
        int pos; cin >> pos;
        pos --;
        if (s[pos] == 'R') {
            s[pos] = 'L';
            if (pos < r) r = pos - 1, lenR = r + 1;
            while (l - 1 >= 0 && s[l - 1] == 'L') lenL ++, l --;
        } else {
            s[pos] = 'R';
            if (pos > l) l = pos, lenL = n - l - 1;
            while (r + 1 < n && s[r + 1] == 'R') lenR ++, r ++;
        }
        cout << lenR << " " << lenL << "\n";
        if (lenL + lenR >= n) cout << "YES\n";
        else cout << "NO\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}