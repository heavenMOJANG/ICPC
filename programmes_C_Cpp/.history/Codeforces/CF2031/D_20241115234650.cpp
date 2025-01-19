#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
class DSU {
private:
    int len;
    vector<int> fat, siz;
    bool isSame (int x, int y) { return x == y; }
public:
    DSU(vector<int> & Info) : len(Info.size()), fat(len + 1), siz(len + 1) { 
        iota(fat.begin(), fat.end(), 0);
        for (int i = 1; i <= len; ++ i) siz[i] = Info[i];
    }
    int findSet(int x) { return fat[x] == x ? x : fat[x] = findSet(fat[x]); }
    void mergeSet(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (isSame(x, y)) return;
        if (siz[x] > siz[y]) fat[y] = x, siz[x] += siz[y];
        else fat[x] = y, siz[y] += siz[x];
        return;
    }
    int getVal(int x) { return fat[x]; }
};
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    DSU dsu(a);
    vector<int> st(n + 1);
    int top = -1;
    for (int i = 1; i <= n; ++ i) {
        int tmp = a[i];
        while (top != -1 && a[i] < st[top]) {
            dsu.mergeSet(st[top], i);
            tmp = max(tmp, a[st[top --]]);
        }
        a[i] = tmp;
        st[++ top] = i;
    }
    for (int i = 1; i <= n; ++ i) cout << a[dsu.findSet(i)] << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}