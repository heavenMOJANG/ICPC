#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
int stk[N], top = -1;
void solve() {
    int n; cin >> n;
    while (n --) {
        int op, x; cin >> op;
        switch (op) {
            case 0:
                if (~top) cout << stk[top] << "\n";
                else cout << "Empty Stack Error\n";
                break;
            case 1:
                cin >> x;
                if (top < N - 1) stk[++ top] = x;
                else cout << "Full Stack Error\n";
                break;
            case 2:
                if (~top) cout << stk[top --] << "\n";
                else cout << "Empty Stack Error\n";
                break;
            case 3:
                cout << top + 1 << "\n";
                break;
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}