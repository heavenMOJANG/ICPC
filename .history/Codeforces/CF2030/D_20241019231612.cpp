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
    int lenL{}, lenR{};
    for (int i = 0; i < n; ++ i)
        if (s[i] == 'R') lenR ++;
        else break;
    for (int i = n - 1; i >= 0; -- i)
        if (s[i] == 'L') lenL ++;
        else break;
    while (q --) {
        int pos; cin >> pos;
        if (s[pos] == 'R') {
            s[pos] = 'L';
            if (pos <= lenR) lenR = pos;
            while ()
            
        } else {
            s[pos] = 'R';
            if (pos == lenR) lenR ++;
            if (pos >= n - lenL + 1) lenL = n - pos + 1;
            
        }
        cout << lenL << " " << lenR << "\n";
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