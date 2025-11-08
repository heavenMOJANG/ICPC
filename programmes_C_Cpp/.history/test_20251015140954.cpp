#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a = 2, b = 1;
	if (b == 0) {
		if (a == 0)cout << "biii\nstop"; // 红灯
		if (a == 1)cout << "dudu\nmove"; // 绿灯
		if (a == 2)cout << "-\nstop";
	}
	else {
		cout << "-\n";
		if (a == 0)cout << "stop"; // 红灯
		if (a == 1)cout << "move"; // 绿灯
		if (a == 2)cout << "stop";
	}

	return 0;
}