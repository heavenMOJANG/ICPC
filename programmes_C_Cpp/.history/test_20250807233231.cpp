#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for(ll &x: a) cin >> x;
        for(ll &x: b) cin >> x;

        // 1) Initial total cost V0
        ll V0 = 0;
        vector<pair<ll,ll>> iv(n);
        for(int i=0;i<n;i++){
            V0 += llabs(a[i] - b[i]);
            ll lo = min(a[i], b[i]);
            ll hi = max(a[i], b[i]);
            iv[i] = {lo, hi};
        }

        // 2) Sort intervals by lo
        sort(iv.begin(), iv.end());

        // 3) Sweep, keep a sorted multiset of previous hi's
        multiset<ll> S;
        ll bestGap = LLONG_MAX;
        for(auto &p : iv){
            ll lo = p.first, hi = p.second;
            // Find largest h <= lo
            auto it = S.upper_bound(lo);
            if(it != S.begin()){
                --it;
                bestGap = min(bestGap, lo - *it);
            }
            S.insert(hi);
        }

        // 4) If no non-overlapping found, bestGap stayed INF -> gain = 0
        ll extra = 0;
        if(bestGap != LLONG_MAX)
            extra = 2LL * bestGap;

        // 5) Final answer
        cout << (V0 + extra) << "\n";
    }
    return 0;
}
