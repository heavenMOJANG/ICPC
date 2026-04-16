#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MAXN = 1e7 + 10;
int ls[MAXN], rs[MAXN], sm[MAXN], idx{};
int newNode(int f) {
    idx ++;
    ls[idx] = ls[f];
    rs[idx] = rs[f];
    sm[idx] = sm[f];
    return idx;
}
int update(int now, int pl, int pr, int p, int val) {
    int cur = newNode(now);
    if (pl == pr) { sm[cur] = val; return cur; }
    int mid = pl + pr >> 1;
    if (p <= mid) ls[cur] = update(ls[cur], pl, mid, p, val);
    else rs[cur] = update(rs[cur], mid + 1, pr, p, val);
    sm[cur] = sm[ls[cur]] + sm[rs[cur]];
    return cur;
}
int query(int now, int pl, int pr, int ql, int qr) {
    if (!now || qr < pl || pr < ql) return 0;
    if (ql <= pl && pr <= qr) return sm[now];
    int mid = pl + pr >> 1;
    return query(ls[now], pl, mid, ql, qr) + query(rs[now], mid + 1, pr, ql, qr);
}
void solve() {
    int N, M, Q; cin >> N >> M >> Q:
    vector<int> rt(N + 1, 0);
    while (Q --) {
        int op; cin >> op;
        if (op == 1) {
            int X, Y; cin >> X >> Y;
            rt[X] = rt[Y];
        } else if (op == 2) {
            int X, Y, Z; cin >> X >> Y >> Z;
            rt[X] = update(rt[X], 1, M, Y, Z);
        } else {
            int X, L, R; cin >> X >> L >> R;
            cout << query(rt[X], 1, M, L, R) << "\n";
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