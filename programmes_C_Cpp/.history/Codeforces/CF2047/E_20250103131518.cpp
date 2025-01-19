#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Count{
    int l{}, r{};
    void add(int d) {
        l += d;
        if (d < 0) r -= d;
    }
    void operator += (const Count & c) {
        l += c.l;
        r += c.r;
    }
    int getMin() { return min(l, r); }
};
struct Tree{

};
Tree* NewNode();

void solve() {
    int n; cin >> n;
    
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}