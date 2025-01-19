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
    auto getNext = [&](string str) {
        vector<int> v(str.size() + 10);
        v[0] = 0; v[1] = 0;
        for (int i = 1; i < str.size(); ++ i) {
            int j = v[i];
            while (j && str[i] != str[j]) j = v[j];
            if (str[i] == str[j]) v[i + 1] = j + 1;
            else v[i + 1] = 0;
        }
        return v;
    };
    vector nxt = getNext(a);
    auto kmp = [&](string str1, string str2) {
        vector nxt = getNext(str1);
        int cnt = 0, lst = -1, j = 0;

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
    vector nxt1 = getNext(a + b); 
    vector nxt2 = getNext(b + a);
    ans = min({ans, lenAB - nxt1[lenAB], lenAB - nxt2[lenAB]});
    cout << ans << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}