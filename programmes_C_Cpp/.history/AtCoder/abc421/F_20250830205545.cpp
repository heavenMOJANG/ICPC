#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 500000 + 10;

int Q;
vector<int> L(N, -1), R(N, -1), P(N, -1);
vector<int> siz(N, 0), acc(N, 0), rk(N, 0), val(N, 0);
int rt = -1;
int getSiz(int x) { return x == -1 ? 0 : siz[x]; }
int getAcc(int x) { return x == -1 ? 0 : acc[x]; }

mt19937 rnd((unsigned)time(nullptr));

void pull(int p) {
    if (p == -1) return;
    siz[p] = getSiz(L[p]) + getSiz(R[p]) + 1;
    acc[p] = val[p] + getAcc(L[p]) + getAcc(R[p]);
    if (L[p] != -1) P[L[p]] = p;
    if (R[p] != -1) P[R[p]] = p;
}

// split p into l (first k nodes) and r (rest)
void split(int p, int k, int& l, int& r) {
    if (p == -1) { l = r = -1; return; }
    if (getSiz(L[p]) >= k) {
        int nl;
        split(L[p], k, l, nl);
        L[p] = nl;                    // <-- 必须把 nl 赋回 L[p]
        if (L[p] != -1) P[L[p]] = p;
        P[p] = -1;
        r = p;
        pull(r);
    } else {
        int nr;
        split(R[p], k - getSiz(L[p]) - 1, nr, r);
        R[p] = nr;
        if (R[p] != -1) P[R[p]] = p;
        P[p] = -1;
        l = p;
        pull(l);
    }
}

int merge(int l, int r) {
    if (l == -1) { if (r != -1) P[r] = -1; return r; }
    if (r == -1) { P[l] = -1; return l; }
    if (rk[l] < rk[r]) {
        R[l] = merge(R[l], r);
        if (R[l] != -1) P[R[l]] = l;
        pull(l);
        P[l] = -1;
        return l;
    } else {
        L[r] = merge(l, L[r]);
        if (L[r] != -1) P[L[r]] = r;
        pull(r);
        P[r] = -1;
        return r;
    }
}

// get 0-based index of node p in current treap
int rnk_idx(int p) {
    int idx = getSiz(L[p]);
    int cur = p;
    while (P[cur] != -1) {
        int par = P[cur];
        if (cur == R[par]) idx += 1 + getSiz(L[par]); // 累加父节点左子树和父节点自己
        cur = par;
    }
    return idx;
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    cin >> Q;
    val[0] = 0;
    acc[0] = 0;
    L[0] = R[0] = P[0] = -1;
    siz[0] = 1;
    rk[0] = rnd();
    rt = 0;

    for (int i = 1; i <= Q; ++i) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            val[i] = i;
            acc[i] = i;
            L[i] = R[i] = P[i] = -1;
            siz[i] = 1;
            rk[i] = rnd();
            int idx = rnk_idx(x);
            int a, b;
            split(rt, idx + 1, a, b);
            int t = merge(a, i);
            rt = merge(t, b);
        } else {
            int x, y; cin >> x >> y;
            int rx = rnk_idx(x), ry = rnk_idx(y);
            int l = min(rx, ry), rpos = max(rx, ry);
            int a, b;
            split(rt, l + 1, a, b);
            int len = rpos - l - 1;
            if (len > 0) {
                int mid, c;
                split(b, len, mid, c);
                long long ans = getAcc(mid);
                cout << ans << '\n';
                rt = merge(a, c);
            } else {
                cout << 0 << '\n';
                rt = merge(a, b);
            }
        }
    }
    return 0;
}
