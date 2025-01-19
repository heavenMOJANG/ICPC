#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    int m; cin >> m;
    for (int i = 1; i <= m; ++ i) {
        string s; cin >> s;
        if (s.size() != n) {cout << "NO\n"; continue;}
        map<char, set<int>> mpC;
        map<int, set<char>> mpN;
        for (int j = 0; j < s.size(); ++ j) {
            mpC[s[j]].insert(a[j + 1]);
            mpN[a[j + 1]].insert(s[j]);
            if (mpC[s[j]].size() > 1 || mpN[a[j + 1]].size() > 1) {cout << "NO\n"; continue;}
        }
        cout << "YES\n";
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}