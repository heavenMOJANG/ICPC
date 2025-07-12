#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// compute ceil(log2(d)), for d>=1
int ceil_log2(ll d) {
    // if exactly a power of 2, return its exponent
    if ((d & (d-1)) == 0) {
        return 63 - __builtin_clzll(d);
    }
    // otherwise floor(log2(d)) + 1
    return 64 - __builtin_clzll(d) - 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<ll> X(N);
    for(int i = 0; i < N; i++){
        cin >> X[i];
    }
    sort(X.begin(), X.end());
    if (M >= N) {
        cout << 0 << "\n";
        return 0;
    }

    // build gaps
    vector<pair<ll,int>> gaps;
    gaps.reserve(N-1);
    for(int i = 0; i < N-1; i++){
        gaps.emplace_back(X[i+1] - X[i], i);
    }

    // pick the M-1 largest gaps
    sort(gaps.begin(), gaps.end(),
         [](auto &a, auto &b){ return a.first > b.first; });

    vector<bool> is_break(N-1, false);
    for(int i = 0; i < M-1; i++){
        is_break[gaps[i].second] = true;
    }

    // sweep segments
    ll answer = 0;
    int seg_start = 0;
    for(int i = 0; i < N-1; i++){
        if (is_break[i]) {
            // segment is [seg_start .. i]
            ll span = X[i] - X[seg_start];
            if (span > 0) {
                int L = ceil_log2(span);
                int x = max(0, L - 1);
                answer += x;
            }
            seg_start = i + 1;
        }
    }
    // last segment [seg_start .. N-1]
    ll span = X[N-1] - X[seg_start];
    if (span > 0) {
        int L = ceil_log2(span);
        int x = max(0, L - 1);
        answer += x;
    }

    cout << answer << "\n";
    return 0;
}
