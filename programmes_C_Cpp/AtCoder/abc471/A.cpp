#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int A, B; cin >> A >> B;
    if (A + B == 9) { cout << "Nine\n"; return; }
    if (A - B == 9) { cout << "Nine\n"; return; }
    if (A * B == 9) { cout << "Nine\n"; return; }
    if (A == B * 9) { cout << "Nine\n"; return; }
    cout << "Nein\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}