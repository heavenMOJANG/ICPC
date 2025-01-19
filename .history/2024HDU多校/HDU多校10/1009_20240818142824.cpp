#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string a, b; cin >> a >> b;
    if (a.size() > b.size()) swap(a, b);
    int lenA = a.size(), lenB = b.size();
    vector<int> nxt(a.size() + 1);
    nxt[0] = 0; nxt[1] = 0;
    for (int i = 1; i < lenA; ++ i) {
        int j = nxt[i];
        while (j && a[i] != a[j]) j = nxt[j];
        if (a[i] == a[j]) nxt[i + 1] = j + 1;
        else nxt[i + 1] = 0;
    }
    int cnt = 0, lst = -1;
    int j = 0;
    for (int i = 0; i < lenB; ++ i) {
        while (j && b[i] != a[j]) j = nxt[j];
        if (b[i] == a[j]) j ++;
        if (j == lenA) cnt ++;
    }
    if (cnt > 1) {cout << "-1\n"; return;}
    if (cnt == 1) {cout << lenB << "\n"; return;}
    int lenAB = lenA + lenB, ans = lenAB;

}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}