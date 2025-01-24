#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        deque<ll> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int kmax = min({ (n + m) / 3, n, m });
        cout << kmax << endl;

        ll res = 0;
        stack<pair<ll, ll>> A, B;
        int cntA = n, cntB = m;
        auto adda = [&] {
            assert(cntA >= 2 && cntB >= 1);
            auto al = a.front(); a.pop_front();
            auto ar = a.back(); a.pop_back();
            res += ar - al;
            cntA -= 2;
            cntB -= 1;
            A.push({ al, ar });
        };
        auto addb = [&] {
            assert(cntB >= 2 && cntA >= 1);
            auto bl = b.front(); b.pop_front();
            auto br = b.back(); b.pop_back();
            res += br - bl;
            cntA -= 1;
            cntB -= 2;
            B.push({ bl, br });
        };
        auto dela = [&] {
            auto [al, ar] = A.top();
            res -= ar - al;
            cntA += 2;
            cntB += 1;
            A.pop();
        };
        auto delb = [&] {
            auto [bl, br] = B.top();
            res -= br - bl;
            cntA += 1;
            cntB += 2;
            B.pop();
        };

        for (int k = 0; k < kmax; k++) {
            if (cntA >= 2 && cntB >= 2 && a.back() - a.front() > b.back() - b.front() || cntA >= 2 && cntB == 1) {
                adda();
            } else if (cntB >= 2 && cntA >= 2 && a.back() - a.front() <= b.back() - b.front() || cntB >= 2 && cntA == 1) {
                addb();
            } else if (cntB == 0) { 
                delb();[  // 反悔
                adda();
                adda();
            } else if (cntA == 0) {
                dela();
                addb();
                addb();
            } else {
                assert(false);
            }
            cout << res << " ";
        }
        cout << endl;
    }

    return 0;
}