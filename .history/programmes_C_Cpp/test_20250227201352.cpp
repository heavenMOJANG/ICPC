#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("6.out", "r", stdout);
    vector<int> a;
    int x;
    while (cin >> x) a.emplace_back(x);
    cout << (a.size() == 3e5) << endl;
    fclose(stdout);
    return 0;
}