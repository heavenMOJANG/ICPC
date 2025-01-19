#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    vector<int> vis(26, 0);
    vis[s[0] - 'a'] = 1;
    int p = 0;
    string t = ""; t += s[0];
    for (int i = 1; i < s.size(); ++ i) {
        if (vis[s[i] - 'a']) {
            if (p && t[p - 1] == s[i]) p --;
            else if (p + 1 < t.size() && t[p + 1] == s[i]) p ++;
            else {cout << "NO\n"; return;}
        } else {
            if (!p) t = s[i] + t;
            else if (p == t.size() - 1) t += s[i], p ++;
            else {cout << "NO\n"; return;}
        }
        vis[s[i] - 'a'] = 1;
    }
    for (int i = 0; i < 26; ++ i) if (!vis[i]) t += char(i + 'a');
    cout << "YES\n" + t << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}