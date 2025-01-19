#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    auto ask = [&](string s) {
        cout << "? " + s << endl;
        int answer; cin >> answer;
        return answer;
    };
    auto print = [&](string s) {
        cout << "! " + s << endl;
    };
    string t = "";
    while ((int)t.size() < n) {
        if (ask(t + "0")) t += "0";
        else if (ask(t + "1")) t += "1";
        else break;
    }
    while ((int)t.size() < n) {
        if (ask("0" + t)) t = "0" + t;
        else t = "1" + t;
    }
    print(t);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}