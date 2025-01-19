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
    vector<int> nxt(a.size() + 10);
    auto getNext = [&](string str, vector<int>& v) {
        v[0] = 0; v[1] = 0;
        for (int i = 1; i < lenA; ++ i) {
            int j = v[i];
            while (j && a[i] != a[j]) j = v[j];
            if (a[i] == a[j]) v[i + 1] = j + 1;
            else v[i + 1] = 0;
        }
        return v;
    };
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
    vector<int> nxt1(lenAB + 2), nxt2(lenAB + 2);
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}