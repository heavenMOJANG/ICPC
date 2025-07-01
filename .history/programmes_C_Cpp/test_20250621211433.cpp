#include <bits/stdc++.h>
using namespace std;
static const int MOD = 998244353;

// fast exponentiation mod
long long modpow(long long a, long long e=MOD-2) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<long long,int>> events;
    events.reserve(6LL*N);

    for(int i = 0; i < N; i++){
        for(int k = 0; k < 6; k++){
            long long x;
            cin >> x;
            events.emplace_back(x, i);
        }
    }

    sort(events.begin(), events.end(),
         [&](auto &a, auto &b){
             return a.first < b.first;
         });

    // precompute inverses of 1..6
    long long inv1 = 1,
              inv2 = modpow(2),
              inv3 = modpow(3),
              inv4 = modpow(4),
              inv5 = modpow(5),
              inv6 = modpow(6);
    long long invs[7] = {0, inv1, inv2, inv3, inv4, inv5, inv6};

    // inv6^N
    long long inv6N = modpow(inv6, N);

    vector<int> cnt(N, 0);
    int zero_cnt = N;           // how many dice still have cnt==0
    long long G = 1;            // product of all cnt[i]>0
    long long prevF = 0, ans = 0;

    // sweep through each distinct face-value v
    int M = events.size();
    for(int i = 0; i < M; ){
        long long v = events[i].first;

        // process all events with this same v
        int j = i;
        while(j < M && events[j].first == v){
            int d = events[j].second;
            int oldc = cnt[d];
            int newc = oldc + 1;
            cnt[d] = newc;

            if(oldc == 0){
                // first time die d becomes >0
                zero_cnt--;
                // multiply G by newc
                G = (G * newc) % MOD;
            } else {
                // replaced factor oldc by newc
                // G = G * newc/oldc
                G = G * newc % MOD * invs[oldc] % MOD;
            }
            j++;
        }

        // now all cnt updated for threshold v
        long long Fv = 0;
        if(zero_cnt == 0){
            // every die has at least one face <= v
            Fv = G * inv6N % MOD;
        }

        // add v * (Fv - prevF) to ans
        long long diff = (Fv - prevF + MOD) % MOD;
        ans = (ans + v % MOD * diff) % MOD;

        prevF = Fv;
        i = j;
    }

    cout << ans << "\n";
    return 0;
}
