#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    vector<long long> count_d(2 * n + 2, 0);
    vector<long long> sum_zb_d(2 * n + 2, 0);
    vector<long long> sum_ob_d(2 * n + 2, 0);

    int zb = 0;
    for (int y = 1; y <= n; ++y) {
        if (b[y - 1] == '0') {
            zb++;
        }
        int ob = y - zb;
        int d = y - 2 * zb;
        int idx = d + n;
        count_d[idx]++;
        sum_zb_d[idx] += zb;
        sum_ob_d[idx] += ob;
    }

    vector<long long> p_count(2 * n + 2, 0);
    vector<long long> p_sum_zb(2 * n + 2, 0);
    vector<long long> p_sum_ob(2 * n + 2, 0);

    p_count[0] = count_d[0];
    p_sum_zb[0] = sum_zb_d[0];
    p_sum_ob[0] = sum_ob_d[0];

    for (int i = 1; i <= 2 * n + 1; ++i) {
        p_count[i] = p_count[i - 1] + count_d[i];
        p_sum_zb[i] = p_sum_zb[i - 1] + sum_zb_d[i];
        p_sum_ob[i] = p_sum_ob[i - 1] + sum_ob_d[i];
    }

    long long total_count = p_count[2 * n + 1];
    long long total_sum_zb = p_sum_zb[2 * n + 1];
    long long total_sum_ob = p_sum_ob[2 * n + 1];

    long long total_f_sum = 0;
    int za = 0;
    for (int x = 1; x <= n; ++x) {
        if (a[x - 1] == '0') {
            za++;
        }
        int oa = x - za;
        int c_x = 2 * za - x;
        int idx = c_x + n;
        
        long long s_x = 0;

        // Caso 1: 2*za - x > y - 2*zb  (ou seja, C_x > D_y)
        // Adicionar oa + ob
        if (idx > 0) {
            long long count_le = p_count[idx - 1];
            long long sum_ob_le = p_sum_ob[idx - 1];
            s_x += (long long)oa * count_le + sum_ob_le;
        }

        // Caso 2: 2*za - x <= y - 2*zb (ou seja, C_x <= D_y)
        // Adicionar za + zb
        long long count_ge = total_count - (idx > 0 ? p_count[idx-1] : 0);
        long long sum_zb_ge = total_sum_zb - (idx > 0 ? p_sum_zb[idx-1] : 0);
        s_x += (long long)za * count_ge + sum_zb_ge;
        
        total_f_sum += s_x;
    }

    cout << total_f_sum << endl;
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