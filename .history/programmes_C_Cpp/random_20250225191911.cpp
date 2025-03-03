#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 1e5 + 10;
constexpr int MAX = 1e5;
mt19937 rnd(time(0));
int fa[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) { fa[find(x)] = find(y); }
signed main(){
    cout.tie() -> sync_with_stdio(0);
    freopen("6.in", "w", stdout);
    int n = rnd() % (N - 10) + 1;
    cout << n << endl;
    for (int i = 1; i <= n; ++ i) {
        cout << rnd() % n + 1;
        if (i == n) cout << endl;
        else cout << " ";
    }
    if (n == 1) return 0;
    iota(fa + 1, fa + n + 1, 1);
    int cnt{};
    for (int i = 0; i < 10 * N; ++ i) {
        int u = rnd() % n + 1;
        int v = rnd() % n + 1;
        if (u == v) continue;
        if (find(u) != find(v) && cnt < n) {
            merge(u, v);
            cnt ++;
            cout << u << " " << v << endl;
        }
    }
    fclose(stdout);
    return 0;
}
