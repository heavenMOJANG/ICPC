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
        vector<int>v, vis(m, 0);
        for (int i = l; i <= r; ++ i) v.emplace_back(e[i]);
        sort(v.begin(), v.end());
        int flag = 0;
        for (int i = 0; i < v.size() - 6; ++ i) {
            if (v[i] + v[i + 4] > v[i + 5] && v[i + 1] + v[i + 2] > v[i + 3]) {flag = 1; break;}
			if (v[i + 1] + v[i + 4] > v[i + 5] && v[i] + v[i + 2] > v[i + 3]) {flag = 1; break;}
			if (v[i + 2] + v[i + 4] > v[i + 5] && v[i] + v[i + 1] > v[i + 3]) {flag = 1; break;}
			if (v[i] + v[i + 1] > v[i + 4] && v[i + 2] + v[i + 3] > v[i + 5]) {flag = 1; break;}
			if (v[i] + v[i + 2] > v[i + 4] && v[i + 1] + v[i + 3] > v[i + 5]) {flag = 1; break;}
			if (v[i] + v[i + 3] > v[i + 4] && v[i + 1] + v[i + 2] > v[i + 5]) {flag = 1; break;}
			if (v[i + 1] + v[i + 2] > v[i + 4] && v[i] + v[i + 3] > v[i + 5]) {flag = 1; break;}
        }
        if (flag) cout << "YES\n";
	    else {
			int cur = 0;
			for (int i = 0; i < v.size() - 2; ++ i)
				if (v[i] + v[i + 1] > v[i + 2]) {
					cur ++;
					if(cur == 2) break;
					i += 2;
				}
			cout << (cur >= 2 ? "YES\n" : "NO\n");
		}
    }
    return 0;
}