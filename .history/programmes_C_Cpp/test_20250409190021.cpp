#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
struct Node { int pre, data, next; };
void solve() {
	vector<Node> a(N);
	int head, n; cin >> head >> n;
	int lst;
	for (int i{}; i < n; ++ i) {
		int adr, data, next; cin >> adr >> data >> next;
		a[adr].data = data;
		a[adr].next = next;
		if (next != -1) a[next].pre = adr;
		else lst = adr;
	}
	for (;;) {
		cout << setw(5) << setfill('0') << lst << " " << a[lst].data << " ";
		if (lst == head) { cout << "-1\n"; break; }
		else { cout << setw(5) << setfill('0') << head << "\n"; }
		lst = a[lst].pre;
		cout << setw(5) << setfill('0') << head << " " << a[head].data << " ";
		if (lst == head) { cout << "-1\n"; break; }
		else { cout << setw(5) << setfill('0') << lst << "\n"; }
		head = a[head].next;
	}
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}