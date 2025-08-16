#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto && x : p) cin >> x;
    int l{}, r = n - 1;
    string ans{};
    vector<int> q;
    auto check = [&]() {
        if (q.size() < 5) return false;
        bool inc = true, dec = true;
        for (int i = q.size() - 5; i < q.size() - 1; ++ i) {
            if (q[i] > q[i + 1]) inc = false;
            if (q[i] < q[i + 1]) dec = false;
        }
        return inc || dec;
    };
    while (l <= r) {
        if (l == r) { ans += "L"; break; }
        int bl{}; q.emplace_back(p[l]);
        if (check()) bl = 1; q.pop_back();
        int br{}; q.emplace_back(p[r]);
        if (check()) br = 1; q.pop_back();
        char choice;
        if (bl) choice = 'R';
        else if (br) choice = 'L';
        else {
            int c1{}; q.push_back(p[l]);
            if (l < r) {
                q.push_back(p[l + 1]);
                if (!check()) c1 ++;
                q.pop_back();
                if (l + 1 < r) {
                    q.push_back(p[r]);
                    if (!check()) c1 ++;
                    q.pop_back();
                }
            }
            q.pop_back();
            int c2{}; q.push_back(p[r]);
            if (l < r) {
                q.push_back(p[l]);
                if (!check()) c2++;
                q.pop_back();
                if (l < r - 1) {
                    q.push_back(p[r - 1]);
                    if (!check()) c2++;
                    q.pop_back();
                }
            }
            q.pop_back();
            if (c1 > c2) choice = 'L';
            else if (c2 > c1) choice = 'R';
            else choice = 'L'; 
        }
        if (choice == 'L') q.push_back(p[l ++]), ans += 'L';
        else q.push_back(p[r --]), ans += 'R';
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}