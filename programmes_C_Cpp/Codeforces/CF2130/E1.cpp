#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int ask(const vector<int>& q) {
    cout << "? " << q.size();
    for (int x : q) cout << " " << x;
    cout << endl;
    int res; cin >> res;
    return res;
}
int cal(const vector<int>& v, int op) {
    if (v.size() == 0) return 0ll;
    int r1 = ask(v);
    vector<int> q;
    for (int x : v) q.emplace_back(op), q.emplace_back(x);
    int r2 = ask(q);
    return r2 - r1;
}
void solve() {
    int n; cin >> n;
    int pos = -1, l = 1, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        vector<int> pre;
        for(int i = 1; i <= mid; ++ i) pre.push_back(i);
        if(ask(pre) > 0) pos = mid, r = mid - 1;
        else l = mid + 1;
    }
    int op = -1;
    l = 1, r = pos - 1;
    int tot = ask({1, pos});
    while (l <= r) {
        int mid = l + (r - l) / 2;
        vector<int> sub;
        for (int i = mid; i <= pos; ++ i) sub.push_back(i);
        if (ask(sub) == tot) op = mid, l = mid + 1;
        else r = mid - 1;
    }
    string ans(n, ' ');
    ans[op - 1] = '(';
    vector<int> tmp;
    for (int i = 1; i <= n; ++ i)
        if (i != op) tmp.emplace_back(i);
    stack<vector<int>> q;
    if (!tmp.empty()) q.push(tmp);
    while (!q.empty()) {
        vector<int> cur = q.top(); q.pop();
        if (cur.size() == 1) {
            int idx = cur[0];
            if (ask({op, idx}) == 1) ans[idx - 1] = ')';
            else ans[idx - 1] = '(';
            continue;
        }
        int mid = cur.size() / 2;
        vector<int> a(cur.begin(), cur.begin() + mid);
        vector<int> b(cur.begin() + mid, cur.end());
        int cnt = cal(a, op);
        if (cnt == a.size()) {
            for (int x : a) ans[x - 1] = ')';
            if (!b.empty()) q.push(b);
        } else if (cnt == 0) {
            for (int x : a) ans[x - 1] = '(';
            if (!b.empty()) q.push(b);
        } else {
            if (!a.empty()) q.push(a);
            if (!b.empty()) q.push(b);
        }
    }
    cout << "! " << ans << endl;
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}