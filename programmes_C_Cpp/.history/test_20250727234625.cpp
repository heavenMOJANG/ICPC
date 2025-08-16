#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        vector<int>a(n);
        for(int &x:a) cin >> x;

        // We'll binary-search on v in [1..n].
        int lo = 1, hi = n+1;
        auto check = [&](int v, pii &out_lr)->bool{
            // Build prefix sums of b_i = +1 if a_i>=v else -1
            vector<int> pref(n+1, 0);
            for(int i=1; i<=n; i++){
                pref[i] = pref[i-1] + (a[i-1] >= v ? 1 : -1);
            }
            // Maintain minimum prefix among pref[0..i-k]
            int min_pref = 0, min_pos = 0;
            for(int i=k; i<=n; i++){
                // Update min over pref[i-k]
                if(pref[i-k] < min_pref){
                    min_pref = pref[i-k];
                    min_pos = i-k;
                }
                // Can we end a valid subarray at i?
                if(pref[i] - min_pref >= 0){
                    out_lr = {min_pos+1, i};
                    return true;
                }
            }
            return false;
        };

        pii best_lr;
        // Binary search for the largest v that works.
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            pii dummy;
            if(check(mid, dummy)){
                // mid is feasible → try higher
                lo = mid + 1;
            } else {
                // mid not feasible → go lower
                hi = mid;
            }
        }
        int vmax = lo - 1;
        // Recover the actual segment
        check(vmax, best_lr);

        cout << vmax << " "
             << best_lr.first << " "
             << best_lr.second << "\n";
    }
    return 0;
}
