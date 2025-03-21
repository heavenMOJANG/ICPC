#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
template<class T>
class fenwick {
    int len{};
    vector<T> t;
    fenwick(int n) : len(n), t(n + 1, 0) {};
    int lowbit(int x) { return x & -x; }
    
};
void solve() {
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}