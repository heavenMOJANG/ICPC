#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    int LIM = 9;
    vector<int> p10(10, 1);
    for (int i = 1; i <= 9; ++ i) p10[i] = p10[i - 1] * 10;
    vector<pair<int, int>> v;
    for (int x = 1; x <= 1000000000ll; x <<= 1) v.emplace_back(to_string(x).size(), x);
    vector<>
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}