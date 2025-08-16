#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    if (!(cin >> N >> Q)) return 0;
    vector<int> A(N);
    int maxA = 0;
    ll S = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        maxA = max(maxA, A[i]);
        S += A[i];
    }
    vector<int> B(Q);
    int maxB = 0;
    for (int j = 0; j < Q; ++j) {
        cin >> B[j];
        maxB = max(maxB, B[j]);
    }
    int M = max(maxA, maxB); // up to 1e6
    vector<ll> freq(M + 1, 0);
    for (int v : A) freq[v]++;

    vector<ll> cnt_pref(M + 1, 0), sum_pref(M + 1, 0);
    ll cnt = 0, ssum = 0;
    for (int v = 0; v <= M; ++v) {
        cnt += freq[v];
        ssum += freq[v] * (ll)v;
        cnt_pref[v] = cnt;
        sum_pref[v] = ssum;
    }

    for (int j = 0; j < Q; ++j) {
        int b = B[j];
        int k = b - 1;
        ll T;
        if (k >= M) {
            // all A_i <= M <= k, so sum min(A_i, k) = S
            T = S;
        } else if (k < 0) {
            T = 0; // b == 0 不会出现，但保持健壮
        } else {
            T = sum_pref[k] + (ll)k * ( (ll)N - cnt_pref[k] );
        }
        if (T == S) {
            cout << -1 << '\n';
        } else {
            ll ans = max((ll)b, T + 1);
            if (ans > S) cout << -1 << '\n';
            else cout << ans << '\n';
        }
    }
    return 0;
}
