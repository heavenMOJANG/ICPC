#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;

int ask(const vector<int>& q) {
    if (q.empty()) return 0;
    cout << "? " << q.size();
    for (int x : q) cout << " " << x;
    cout << endl;
    int res; cin >> res;
    if (res == -1) exit(0);
    return res;
}

int find_o(const vector<int>& v) {
    if (v.size() == 1) return v[0];
    
    int mid = v.size() / 2;
    vector<int> a(v.begin(), v.begin() + mid);
    vector<int> b(v.begin() + mid, v.end());

    int va = ask(a);
    vector<int> ab = a;
    ab.insert(ab.end(), b.begin(), b.end());
    int vab = ask(ab);
    int vb = ask(b);

    if (vab > va + vb) {
        return find_o(a);
    } else {
        return find_o(b);
    }
}

int cnt_c(const vector<int>& v, int op) {
    if (v.empty()) return 0;
    int v1 = ask(v);
    
    vector<int> q;
    for (int x : v) {
        q.push_back(op);
        q.push_back(x);
    }
    int v2 = ask(q);

    return v2 - v1;
}

void solve() {
    int n;
    cin >> n;

    vector<int> all(n);
    iota(all.begin(), all.end(), 1);

    int op = find_o(all);

    string ans(n, ' ');
    ans[op - 1] = '(';

    vector<int> uk;
    for (int i = 1; i <= n; ++i) {
        if (i != op) {
            uk.push_back(i);
        }
    }

    vector<vector<int>> q;
    if (!uk.empty()) {
        q.push_back(uk);
    }

    while (!q.empty()) {
        vector<int> cur = q.back();
        q.pop_back();

        if (cur.size() == 1) {
            int idx = cur[0];
            if (ask({op, idx}) == 1) {
                ans[idx - 1] = ')';
            } else {
                ans[idx - 1] = '(';
            }
            continue;
        }

        int mid = cur.size() / 2;
        vector<int> a(cur.begin(), cur.begin() + mid);
        vector<int> b(cur.begin() + mid, cur.end());

        int cc = cnt_c(a, op);

        if (cc == a.size()) {
            for (int x : a) ans[x - 1] = ')';
            if (!b.empty()) q.push_back(b);
        } else if (cc == 0) {
            for (int x : a) ans[x - 1] = '(';
            if (!b.empty()) q.push_back(b);
        } else {
            if (!a.empty()) q.push_back(a);
            if (!b.empty()) q.push_back(b);
        }
    }

    cout << "! " << ans << endl;
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}