#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
using i64 = int;
void solve() {
    i64 n, m, k;
    std::cin >> n >> m >> k;
    i64 tot = 2LL * (n + m) - 8;
    int s = 0;
    for (int i = 0; i < k; ++ i) {
    	int x, y, z;
    	std::cin >> x >> y >> z;
    	if ((x == 1) ^ (x == n) ^ (y == 1) ^ (y == m)) {
    		s ^= z;
    		tot -= 1;
            cout << tot << "\n";
    	}
    }

    if (tot == 0) {
    	if (s) {
    		std::cout << 0 << "\n";
    	} else {
    		std::cout << pow(2, n * m - k) << "\n";
    	}
    } else {
    	std::cout << pow(2, n * m - k - 1) << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}