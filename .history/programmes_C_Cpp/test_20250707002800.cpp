#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> p_sum(n + 1, 0);
    ll total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p_sum[i + 1] = p_sum[i] + a[i];
    }
    total_sum = p_sum[n];

    if (total_sum % 2 != 0) {
        cout << -1 << endl;
        return;
    }

    ll H = total_sum / 2;

    // 1-op solution
    for (int p = 1; p < n; ++p) {
        if (p_sum[p] == H) {
            cout << 1 << endl;
            for (int i = 0; i < n; ++i) {
                cout << a[i] << (i == n - 1 ? "" : " ");
            }
            cout << endl;
            return;
        }
    }

    // 2-op solution
    vector<ll> max_psum_lt_H(n, -1);
    vector<int> max_psum_lt_H_idx(n, -1);
    if (p_sum[1] < H) {
        max_psum_lt_H[0] = p_sum[1];
        max_psum_lt_H_idx[0] = 1;
    }
    for (int i = 1; i < n - 1; ++i) {
        max_psum_lt_H[i] = max_psum_lt_H[i - 1];
        max_psum_lt_H_idx[i] = max_psum_lt_H_idx[i-1];
        if (p_sum[i + 1] < H) {
            if (p_sum[i + 1] > max_psum_lt_H[i]) {
                max_psum_lt_H[i] = p_sum[i + 1];
                max_psum_lt_H_idx[i] = i + 1;
            }
        }
    }
    
    for (int p2 = 1; p2 < n; ++p2) {
        if (p_sum[p2] > H && p2 > 1) {
            if (max_psum_lt_H_idx[p2 - 2] != -1) {
                ll required_psum = p_sum[p2] - H;
                if (max_psum_lt_H[p2 - 2] >= required_psum) {
                    int p1 = max_psum_lt_H_idx[p2-2];
                    
                    cout << 2 << endl;
                    vector<ll> b1(n, 0), b2(n, 0);
                    ll X = p_sum[p2] - H;
                    ll T1 = X;

                    // Construct b1
                    ll rem_X = X;
                    for (int i = p1; i < p2; ++i) {
                        ll take = min(a[i], rem_X);
                        b1[i] = take;
                        rem_X -= take;
                    }
                    rem_X = T1;
                    for (int i = 0; i < p1; ++i) {
                        ll take = min(a[i], rem_X);
                        b1[i] = take;
                        rem_X -= take;
                    }
                    
                    // Construct b2
                    for(int i = 0; i < n; ++i) b2[i] = a[i] - b1[i];

                    for (int i = 0; i < n; ++i) cout << b1[i] << (i == n - 1 ? "" : " ");
                    cout << endl;
                    for (int i = 0; i < n; ++i) cout << b2[i] << (i == n - 1 ? "" : " ");
                    cout << endl;
                    return;
                }
            }
        }
    }


    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}