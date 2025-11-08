#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to compute number of digits in n
int num_digits(ll n) {
    if (n == 0) return 1;
    return floor(log10(n)) + 1;
}

// Function to solve a single test case
ll solve(ll C, ll D) {
    // Number of digits in C
    int d = num_digits(C);
    // Maximum number of digits in C+D
    int max_digits = num_digits(C + D);
    
    ll count = 0;
    // Iterate over possible number of digits for C+x
    for (int m = d; m <= max_digits; ++m) {
        // Compute 10^(m-1) and 10^m
        ll pow_m_minus_1 = 1LL;
        for (int i = 0; i < m - 1; ++i) pow_m_minus_1 *= 10;
        ll pow_m = pow_m_minus_1 * 10;
        
        // Range of x such that C+x has m digits
        ll x_min = max(1LL, pow_m_minus_1 - C);
        ll x_max = min(D, pow_m - C - 1);
        if (x_min > x_max) continue;
        
        // k^2 = C * 10^m + (C + x)
        // x = k^2 - (C * 10^m + C)
        // k^2 ranges from C * 10^m + (C + x_min) to C * 10^m + (C + x_max)
        ll lower = C * pow_m + C + x_min;
        ll upper = C * pow_m + C + x_max;
        
        // Find k range: k_min <= k <= k_max where k^2 is in [lower, upper]
        ll k_min = ceill(sqrtl(lower));
        ll k_max = floorl(sqrtl(upper));
        
        // Count valid k where x = k^2 - (C * 10^m + C) satisfies constraints
        for (ll k = k_min; k <= k_max; ++k) {
            ll x = k * k - (C * pow_m + C);
            if (x_min <= x && x <= x_max) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        ll C, D;
        cin >> C >> D;
        cout << solve(C, D) << '\n';
    }
    
    return 0;
}