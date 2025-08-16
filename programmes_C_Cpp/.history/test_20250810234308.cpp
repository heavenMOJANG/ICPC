#include <bits/stdc++.h>
using namespace std;

bool can_transform(vector<unsigned int> a, const vector<unsigned int>& b) {
    int n = a.size();
    if (a[n - 1] != b[n - 1]) return false;
    if (n == 1) return a[0] == b[0];

    vector<unsigned int> need(n - 1);
    vector<int> D;
    for (int i = 0; i < n - 1; i++) {
        need[i] = a[i] ^ b[i];
        if (need[i] != 0) D.push_back(i);
    }
    if (D.empty()) return true;

    // 把需要操作的下标 D 分成连续区间
    vector<pair<int,int>> runs;
    int start = -1, prev = -1;
    for (int idx : D) {
        if (start == -1) {
            start = prev = idx;
        } else if (idx == prev + 1) {
            prev = idx;
        } else {
            runs.emplace_back(start, prev);
            start = prev = idx;
        }
    }
    if (start != -1) runs.emplace_back(start, prev);

    // 对每个连续区间独立判断可行性
    for (auto [l, r] : runs) {
        vector<unsigned int> val = a; // 拷贝，保证不影响原数组
        vector<bool> executed(r - l + 1, false);
        deque<int> q;

        for (int i = l; i <= r; i++) {
            if (val[i + 1] == need[i]) q.push_back(i);
        }

        int done = 0;
        while (!q.empty()) {
            int i = q.front(); q.pop_front();
            if (executed[i - l]) continue;
            // 执行操作
            val[i] ^= val[i + 1];
            executed[i - l] = true;
            done++;
            // 检查左邻居是否变成可执行
            if (i - 1 >= l && !executed[i - 1 - l] && val[i] == need[i - 1]) {
                q.push_back(i - 1);
            }
        }
        if (done < (r - l + 1)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<unsigned int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        cout << (can_transform(a, b) ? "YES\n" : "NO\n");
    }
}
