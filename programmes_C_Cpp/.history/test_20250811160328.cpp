#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using i128 = __int128_t;

string to_string_i128(i128 x) {
    if (x == 0) return "0";
    bool neg = x < 0;
    if (neg) x = -x;
    string s;
    while (x > 0) {
        int d = (int)(x % 10);
        s.push_back('0' + d);
        x /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n_ll;
    long long w_ll;
    // read pairs until EOF
    while ( (cin >> n_ll >> w_ll) ) {
        i128 n = (i128)n_ll;
        long long w = w_ll;
        // small safety
        if (n_ll <= 0 || w <= 1) {
            cout << "0\n";
            continue;
        }

        // compute counts by lifetime (count[0] is lifetime 1, etc.)
        vector<i128> counts;
        i128 N = n;
        while (N >= w) {
            i128 e = N / w;      // eliminated in this round
            counts.push_back(e); // temporary; may combine later
            N -= e;              // survivors to next round
        }
        if (counts.empty()) {
            // never entered loop => initial n < w => one round, all lifetime 1
            counts.push_back(N);
        } else {
            // combine last eliminated with final survivors: both have same last lifetime
            counts.back() += N;
        }

        // assign largest values to largest lifetimes: iterate counts from back -> front
        i128 cur = n;     // next largest value to assign
        i128 ans = 0;
        for (int idx = (int)counts.size() - 1; idx >= 0; --idx) {
            i128 k = counts[idx];
            if (k == 0) continue;
            // sum of cur,cur-1,...,cur-k+1
            i128 sumvals = k * ( (i128)2 * cur - k + 1 ) / 2;
            i128 lifetime = (i128)(idx + 1);
            ans += lifetime * sumvals;
            cur -= k;
        }

        cout << to_string_i128(ans) << '\n';
    }

    return 0;
}
