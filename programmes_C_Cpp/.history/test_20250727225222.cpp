#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int &x : p) cin >> x;

        int l = 0, r = n - 1;
        int last = p[l++];
        int up = 1, down = 1;
        string ans;
        ans.reserve(n);
        ans.push_back('L');

        for (int i = 1; i < n; ++i) {
            auto check = [&](int x, int &u_out, int &d_out) {
                int u = (last < x ? up + 1 : 1);
                int d = (last > x ? down + 1 : 1);
                u_out = u; d_out = d;
                return (u <= 4 && d <= 4) ? max(u, d) : 100;
            };

            int uL, dL, uR, dR;
            int scoreL = (l <= r ? check(p[l], uL, dL) : 100);
            int scoreR = (l <= r ? check(p[r], uR, dR) : 100);

            if (scoreL <= scoreR) {
                ans.push_back('L');
                last = p[l++];
                up = uL;
                down = dL;
            } else {
                ans.push_back('R');
                last = p[r--];
                up = uR;
                down = dR;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
