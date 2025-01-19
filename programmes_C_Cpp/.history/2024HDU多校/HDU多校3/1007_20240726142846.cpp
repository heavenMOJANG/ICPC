#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 1e5 + 10;
struct segmentTree {
    int val,tag,isSame,isAsc,isDec,maxn,minn;
}t[N << 2];
int n, a[N];
void build(int p, int pl, int pr) {
    if (pl == pr) {
        t[p].val = a[pl];
        t[p].tag = 0;
        t[p].isSame = 1;
        t[p].isAsc = 1;
        t[p].isDec = 1;
        t[p].maxn = 1;
        t[p].minn = 1;
    }
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