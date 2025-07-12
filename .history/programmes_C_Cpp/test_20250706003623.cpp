#pragma GCC optimize("Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, m;
        ll m;
        cin >> n >> m;
        vector<ll> dp(n+1), ndp(n+1);
        dp[0] = 1;
        for(int i = n; i >= 1; --i){
            fill(ndp.begin(), ndp.end(), 0LL);
            for(int k = 0; k <= n; ++k){
                if(!dp[k]) continue;
                ndp[k] = (ndp[k] + dp[k]) % m;
                ll freeSteps = (ll)(n - i + 1) - k;
                if(freeSteps > 0){
                    ll add = dp[k];
                    add = add * i % m;
                    add = add * freeSteps % m;
                    ndp[k+1] = (ndp[k+1] + add) % m;
                }
            }
            dp.swap(ndp);
        }
        ll ans = 0;
        for(int k = 0; k <= n; ++k){
            ans = (ans + dp[k]) % m;
        }
        cout << ans << "\n";
    }
    return 0;
}
