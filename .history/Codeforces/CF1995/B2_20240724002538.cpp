#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int inf = 0x7fffffff;
struct Node {int a,c;};
void solve() {
    int n, m; cin >> n >> m;
    vector<Node> f(n);
    for (int i = 0; i < n; ++ i) cin >> f[i].a;
    for (int i = 0; i < n; ++ i) cin >> f[i].c;
    sort(f.begin(), f.end(), [](const Node & x, const Node & y) {
        return x.a < y.a;
    });
    priority_queue<pii>pq;
    int maxn = 0;
    for (int i = 0; i < n - 1; ++ i) {
        if (f[i + 1].a - f[i].a <= 1) {
            int sum = 0, tc = f[i].c, tcc = f[i + 1].c;
            int k = min (tcc, m / f[i + 1].a);
            sum += k * f[i + 1].a;
            tcc -= k;
            int kk = min (tc, (m - sum) / f[i].a);
            sum += kk * f[i].a;
            tc -= kk;
            while(1) {
                if (tc == 0 || tcc == f[i + 1].c) break;
                int tmp = sum - f[i + 1].a; 
                int tk = min(tc, (m - tmp) / f[i].a);
                tmp += tk * f[i].a;
                cout << tmp << "\n";
                tc -= tk, tcc ++;
                if (tmp <= sum) break;
            }
            maxn = max(maxn, sum);
        }
        else {
            int sum = 0;
            int k = min (f[i].c, m / f[i].a);
            sum += k * f[i].a;
            maxn = max(maxn, sum);
        }
    }
    int sum = 0;
    int k = min (f[n - 1].c, m / f[n - 1].a);
    sum += k * f[n - 1].a;
    maxn = max(maxn, sum);
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}