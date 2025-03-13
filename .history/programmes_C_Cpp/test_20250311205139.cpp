#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct OPT {
    int opt;
    string s0, s1;
    OPT(int o, string s, string t) : opt(o), s0(s), s1(t) {}
};
void solve() {
    int n; cin >> n;
    vector<OPT> a(n);
    for (int i = 0; i < n; ++ i) {
        int opt; cin >> opt;
        string s0, s1;
        if (opt == 1) {
            cin >> s0;
            a.push_back(OPT(opt, s0, ""));
        } else {
            cin >> s0 >> s1;
            a.push_back(OPT(opt, s0, s1));
        }
    }
    string txt; cin >> txt;
    getline(cin, txt);
    for (int i = 0; i < n; ++ i) {
        if (a[i].opt == 3) {
            txt = regex_replace(txt, regex(a[i].s0), a[i].s1);
        } else 
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}