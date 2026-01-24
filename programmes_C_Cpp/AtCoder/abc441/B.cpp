#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    map<char, int> ma, mt;
    for (char c : s) mt[c] = 1;
    for (char c : t) ma[c] = 1;
    int q; cin >> q;
    while (q --) {
        string st; cin >> st;
        int okt = 1, oka = 1;
        for (char c : st) {
            if (mt[c] == 0) okt = 0;
            if (ma[c] == 0) oka = 0;
        }
        if (okt && oka) cout << "Unknown\n";
        else if (okt) cout << "Takahashi\n";
        else if (oka) cout << "Aoki\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}