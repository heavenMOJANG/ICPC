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
    auto getNext = [&](string str) {
        int lens = str.size();
        vector<int> v(lens + 10);
        v[0] = 0; v[1] = 0;
        for (int i = 1; i < lens; ++ i) {
            int j = v[i];
            while (j && str[i] != str[j]) j = v[j];
            if (str[i] == str[j]) v[i + 1] = j + 1;
            else v[i + 1] = 0;
        }
        return v;
    };
    auto kmp = [&](string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();
        vector nxt = getNext(str1);
        int res = 0, lst = -1, j = 0;
        for (int i = 0; i < len2; ++ i) {
            while (j && str2[i] != str1[j]) j = nxt[j];
            if (str2[i] == str1[j]) j ++;
            if (j == len1) res ++;
        }
        return res;
    };
    int lenA = a.size(), lenB = b.size();
    int cnt = kmp(a, b);
    if (cnt > 1) {cout << "-1\n"; return;}
    if (cnt == 1) {cout << lenB << "\n"; return;}
    int lenAB = lenA + lenB, ans = lenAB;
    vector nxt1 = getNext(a + b); 
    vector nxt2 = getNext(b + a);
    vector nxtA = getNext(a);
    vector nxtB = getNext(b);
    string AB = b.substr(nxt2[lenAB], lenB) + a;
    string BA = a.substr(nxt1[lenAB], lenA) + b;
    int cntAB_A{} = kmp(a, AB)
    cout << ans << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}