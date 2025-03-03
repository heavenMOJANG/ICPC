#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 210;
int n, head[N], s, t;
int a[10][10];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    int x, y, z;
    while (cin >> x >> y >> z && x && y && z) a[x][y] = z;
    return 0;
}