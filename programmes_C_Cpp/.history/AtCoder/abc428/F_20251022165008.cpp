#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
struct S { int x, y; };
S op(S a, S b) { return {a.x + b.x, a.y + b.y}; }
S e() { return {0, 0}; }
using F = int;
S mapping(F f, S a) {
    if (f == 0) a.x = 0;
    if (f == 1) a.x = a.y;
    return a;
}
F composition(F f, F g) { return f == -1 ? g : f; }
F id() { return -1; }
int x, y;
bool fa(S a) { return a.x <= x; }
bool fb(S a) { return a.y > y; }
void solve() {
    int n; cin >> n;
    vector<int> w(n);
    for (auto && x : w) cin >> x;
    vector<int> a(n);
    for (int i{}; i < n - 1; ++ i) a[i + 1] = w[n - i - 1] - w[n - i - 2];
    vector<S> A(n), B(n);
    for (int i{}; i < n; ++ i) {
        A[i] = {0, a[i]};
        B[i] = {-a[i], -a[i]};
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> sega(A), segb(B);
    int q; cin >> q;
    while (q --) {
        int op; cin >> op;
        switch (op) {
            case 1:{
                int v; cin >> v;
                v = n - v + 1;
                sega.apply(v, n, 0);
                segb.apply(v, n, 1);
                break;
            }
            case 2:{
                int v; cin >> v;
                v = n - v + 1;
                sega.apply(v, n, 1);
                segb.apply(v, n, 0);
                break;
            }
            default:
                cin >> x;
                y = x - w[n - 1];
                if (y >= 0) { cout << "0\n"; continue; }
                cout << min(sega.max_right<fa>(0), segb.max_right<fb>(0)) << "\n";
        }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}