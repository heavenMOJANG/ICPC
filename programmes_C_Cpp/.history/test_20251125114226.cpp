#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> t(n + 1), val(n + 1);
    stack<int> q;
    for (int i = 1; i <= n; ++ i) cin >> t[i];
    for (int i = 1; i <= n; ++ i) cin >> val[i];
    for (int i = 1; i <= n; ++ i) if (t[i] < i) {//判无解
            cout << -1 << endl;
            return;
    }
    int ans = 0;
    for (int j = n; j >= 0; -- j){//倒着做
        if (j != n) {
            for (int k = 1; k <= t[j+1]-t[j]; ++ k){//若时间变化则更新
                if (q.size()) {
                    ans += q.top();
                    q.pop();
                } else break;
            }
        }
        if(!j)break;
        if (q.size()) q.push(max(q.top(), val[j]));//每次将未更新和之前取 max 后的丢栈顶
        else q.push(val[j]);
    }
    cout << ans << "\n";
    return;
}
void test(int testcase) {
    string inf = to_string(testcase) + ".in";
    string outf = to_string(testcase) + ".out";
    freopen(inf.c_str(), "r", stdin);
    freopen(outf.c_str(), "w", stdout);
    int _ = 1; cin >> _;
    while(_ --) solve();
    fclose(stdin);
    fclose(stdout);
    return;
}
signed main() {
    for (int i = 1; i <= 10; ++ i) test(i);
    return 0;
}