#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 1e5 + 10;
struct segmentTree {
    int val,tag;
    int isAscending,isDecending, isPeak;
    int maxn,minn;
    int sameNumber;
}t[N << 2];
int n, a[N];
void pushup(int p) {
    t[p].val = t[p << 1].val + t[p << 1 | 1].val;
    t[p].maxn = max(t[p << 1].maxn, t[p << 1 | 1].maxn);
    t[p].minn = min(t[p << 1].minn, t[p << 1 | 1].minn);
    if (t[p << 1].sameNumber == t[p << 1 | 1].sameNumber && t[p << 1].sameNumber != -1)
        t[p].sameNumber = t[p << 1].sameNumber;
    else t[p].sameNumber = -1; 
    if (t[p << 1].isAscending && t[p << 1 | 1].isAscending && t[p << 1].maxn < t[p << 1 | 1].minn)
        t[p].isAscending = 1;
    else t[p].isAscending = 0;
    if (t[p << 1].isDecending && t[p << 1 | 1].isDecending && t[p << 1].minn > t[p << 1 | 1].maxn)
        t[p].isDecending = 1;
    else t[p].isDecending = 0;
}
void build(int p, int pl, int pr) {
    if (pl == pr) {
        t[p].val = a[pl];
        t[p].isAscending = 1;
        t[p].isDecending = 1;
        t[p].maxn = 1;
        t[p].minn = 1;
        t[p].sameNumber = t[p].val;
    }
    int mid = pl + pr >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    pushUp(p);
}
void solve() {
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    build(1, 1, n);
    return 0;
}