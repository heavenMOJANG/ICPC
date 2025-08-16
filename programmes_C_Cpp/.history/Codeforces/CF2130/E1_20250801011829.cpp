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
int find(const vector<int>& v) {
    if (v.size() == 1) return v[0];
    int mid = v.size() / 2;
    vector<int> a(v.begin(), v.begin() + mid);
    vector<int> b(v.begin() + mid, v.end());
    int ra = ask(a), rb = ask(b), rv = ask(v);
    if (rv > ra + rb) return find(a);
    else return find(b);
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
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    int op = find(a);
    string ans(n, ' ');
    ans[op - 1] = '(';
    vector<int> tmp;
    for (int i = 1; i <= n; ++ i)
        if (i != op) tmp.emplace_back(i);
    vector<vector<int>> q;
    if (!tmp.empty()) q.push_back(tmp);
    while (!q.empty()) {
        vector<int> cur = q.back(); q.pop_back();
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
            if (!b.empty()) q.push_back(b);
        } else if (cnt == 0) {
            for (int x : a) ans[x - 1] = '(';
            if (!b.empty()) q.push_back(b);
        } else {
            if (!a.empty()) q.push_back(a);
            if (!b.empty()) q.push_back(b);
        }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}