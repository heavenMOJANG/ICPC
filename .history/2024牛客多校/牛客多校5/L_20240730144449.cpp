#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int mod = 998244353;
struct Node{int sum, len;};
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    int sum = 0, len = 0;
    deque<Node> dq;
    for (int i = n; i >= 1; -- i) {
        sum += a[i];
        len ++;
        if (i == 1) {
            dq.push_back(Node{sum, len});
            break;
        }
        if (a[i] < a[i - 1]) {
            int q = sum / len;
            int r = sum % len;
            if (a[i - 1] > q + r) {
                dq.push_back(Node{sum, len});
                sum = 0;
                len = 0;
            } else continue;
        }
    }
    int ans = 1;
    while(!dq.empty())
        if (dq.size() >= 2) {
            Node u = dq.front(); dq.pop_front();
            Node v = dq.front(); dq.pop_front();
            int uq = u.sum / u.len, ur = u.sum % u.len;
            int vq = v.sum / v.len, vr = v.sum % v.len;
            if (uq + ur >= vq){
                Node w = {u.sum + v.sum, u.len + v.len};
                dq.push_front(w);
                cout << w.sum << " " << w.len << "\n";
            }
            else {
                dq.push_front(v);
                for (int i = 1; i <= ur; ++ i) ans = (ans * (uq + 1)) % mod;
                for (int i = ur + 1; i <= len; ++ i) ans = (ans * uq) % mod;
            }
        }
        else {
            Node u = dq.front(); dq.pop_front();
            int uq = u.sum / u.len, ur = u.sum % u.len;
            for (int i = 1; i <= ur; ++ i) ans = (ans * (uq + 1)) % mod, cout << uq + 1 << " ";
            for (int i = ur + 1; i <= len; ++ i) ans = (ans * uq) % mod, cout << uq << " ";
        }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}