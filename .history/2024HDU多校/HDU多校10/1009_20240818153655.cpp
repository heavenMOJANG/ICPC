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
    auto getNext = [&](string pat) {
        int lenp = pat.size();
        vector<int> v(lenp + 1);
        v[0] = 0; v[1] = 0;
        for (int i = 1; i < lenp; ++ i) {
            int j = v[i];
            while (j && pat[i] != pat[j]) j = v[j];
            v[i + 1] = (pat[i] == pat[j] ? j + 1 : 0ll);
        }
        return v;
    };
    auto kmp = [&](string txt, string pat) {
        int lent = txt.size(), lenp = pat.size();
        vector nxt = getNext(pat);
        int res = 0, j = 0;
        for (int i = 0; i < lent; ++ i) {
            while (j && txt[i] != pat[j]) j = nxt[j];
            if (txt[i] == pat[j]) j ++;
            if (j == lenp) res ++;
        }
        return res;
    };
    int lenA = a.size(), lenB = b.size();
    int cnt = kmp(b, a);
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