#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 1e5 + 10;
int n, q, e[N];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> e[i];
    while (q --) {
        int l, r; cin >> l >> r;
        if (r - l + 1 >= 48) {cout << "YES\n"; continue;}
        int m = r - l + 1;
        vector<int>t, vis(m, 0);
        for (int i = l; i <= r; ++ i) t.emplace_back(e[i]);
        sort(t.begin(), t.end());
        int flag1 = 0, flag2 = 0;
        for (int i = 0; i < m - 5; ++ i, vis[i] = 1) {
            for (int j = i + 1; j < m - 4; ++ j) {
                int k = lower_bound(t.begin() + j + 1, t.end(), t[i] + t[j]) - t.begin();
                if (k - 1 > j && t[i] + t[j] > t[k - 1]) {
                    vis[i] = vis[j] = vis[k] = 1;
                    flag1 = 1;
                    break;
                }
            }
        }
        if (flag1) {

        }
        cout << (flag2 ? "YES\n" : "NO\n");
    }
    return 0;
}