#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5e5 + 10;
struct segtree {
    int val, len, llen, rlen;
    char lc, rc;
    segtree() : val{}, len{}, llen{}, rlen{}, lc{}, rc{} {}
    segtree(char ch) : val(1), len(1), llen(1), rlen(1), lc(ch), rc(ch) {}
    friend segtree operator + (const segtree& left, const segtree& right) {
        if (left.len == 0) return right;
        if (right.len == 0) return left;
        segtree res;
        res.len = left.len + right.len;
        res.lc = left.lc;
        res.rc = right.rc;
        if (left.llen == left.len && left.lc == right.lc) res.llen = left.len + right.llen;
        else res.llen = left.llen;
        if (right.rlen == right.len && left.rc == right.lc) res.rlen = right.len + left.rlen;
        else res.rlen = right.rlen;
        res.val = max(left.val, right.val);
        if (left.rc == right.lc) res.val = max(res.val, left.rlen + right.llen);
        return res;
    }
} t[N << 2];
int n, q;
string s;
void pushUp(int p) { t[p] = t[p << 1] + t[p << 1 | 1]; }
void build(int p, int pl, int pr) {
    if (pl == pr) { t[p] = segtree(s[pl - 1]); return; }
    int mid = pl + pr >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    pushUp(p);
}
void update(int p, int pl, int pr, int pos, char ch) {
    if (pl == pr) { t[p] = segtree(ch); return; }
    int mid = pl + pr >> 1;
    if (pos <= mid) update(p << 1, pl, mid, pos, ch);
    else update(p << 1 | 1, mid + 1, pr, pos, ch);
    pushUp(p);
}
segtree query(int p, int pl, int pr, int ql, int qr) {
    if (ql <= pl && pr <= qr) return t[p];
    int mid = pl + pr >> 1;
    segtree lres = query(p << 1, pl, mid, ql, qr);
    segtree rres = query(p << 1 | 1, mid + 1, pr, ql, qr);
    return lres + rres;
}
void solve() {
    cin >> n >> q >> s;
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}