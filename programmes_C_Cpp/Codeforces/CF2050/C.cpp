#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
	string s; cin >> s;
	int sum{}, cnt2{}, cnt3{};
	for (int i = 0; i < (int)s.size(); ++ i) {
		sum += s[i] - '0';
		if (s[i] == '2')
			cnt2 ++;
		if (s[i] == '3')
			cnt3 ++;
	}
	if (sum % 9 == 0) { cout << "YES\n"; return; }
	int d = 9 - sum % 9;
	switch (d) {
		case 1:
			cout << (cnt2 >= 5 || (cnt3 && cnt2 >= 2) ? "YES\n" : "NO\n");
			break;
		case 2:
			cout << (cnt2 ? "YES\n" : "NO\n");
			break;
		case 3:
			cout << (cnt2 >= 6 || (cnt3 && cnt2 >= 3) || cnt3 >= 2 ? "YES\n" : "NO\n");
			break;
		case 4:
			cout << (cnt2 >= 2 ? "YES\n" : "NO\n");
			break;
		case 5:
			cout << (cnt2 >= 7 || (cnt3 && cnt2 >= 4) || (cnt3 >= 2 && cnt2) ? "YES\n" : "NO\n");
			break;
		case 6:
			cout << (cnt2 >= 3 || cnt3 ? "YES\n" : "NO\n");
			break;
		case 7:
			cout << (cnt2 >= 8 || (cnt3 && cnt2 >= 5) || (cnt3 >= 2 && cnt2 >= 2) ? "YES\n" : "NO\n");
			break;
		case 8:
			cout << (cnt2 >= 4 || (cnt3 && cnt2) ? "YES\n" : "NO\n");
			break;
	}
	return;
}
 
signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int _ = 1; cin >> _;
	while (_ --) solve();
	return 0;
}