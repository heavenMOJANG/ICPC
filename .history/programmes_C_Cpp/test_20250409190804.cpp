#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
	int N; cin >> N;
	map<string, int> usr;
	for (int i{}; i < N; ++ i) {
		string name; cin >> name;
		usr[name] = 1;
	}
	int M; cin >> M;
	vector<pair<string, int>> input;
	double tot{};
	for (int i{}; i < M; ++ i) {
		string name; int num; cin >> name >> num;
		tot += num;
		input.emplace_back(name, num);
	}
	tot /= M;
	set<string> ans;
	for (auto [name, num] : input) {
	}
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}