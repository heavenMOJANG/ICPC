#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s;
    string pre;
    for (int i = 1; i <= n; ++ i) {
        cin >> s;
        if (i >= 2) {
            if (s == "sweet" && pre == "sweet") {
                if (i != n) {cout << "No\n"; return;}
            }
        }
        pre = s;
    }
    cout << "Yes\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}