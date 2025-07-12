#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<ll> a(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        // 1. 前缀最小 pm[i] 和它的前缀和 P[i]
        vector<ll> pm(n+1), P(n+1);
        pm[1] = a[1];
        P[1]  = pm[1];
        for(int i = 2; i <= n; i++){
            pm[i] = min(pm[i-1], a[i]);
            P[i]  = P[i-1] + pm[i];
        }

        // 2. 构造前缀或 G[i]：是否存在 k (2 ≤ k ≤ i) 使得 a[k] ≥ pm[k-1]
        vector<int> G(n+1);
        G[1] = 0;
        for(int i = 2; i <= n; i++){
            int good = (a[i] >= pm[i-1]) ? 1 : 0;
            G[i] = G[i-1] | good;
        }

        // 3. 枚举 j，从三种情况中取最优
        //    (1) 不操作：P[n]
        //    (2) 选 i ≥ 2：当 G[j-1] == 1 时，总和 = P[j-1]
        //    (3) 选 i = 1：总和 = P[j-1] + a[j]
        ll ans = P[n];
        for(int j = 2; j <= n; j++){
            if(G[j-1]){
                ans = min(ans, P[j-1]);
            }
            ans = min(ans, P[j-1] + a[j]);
        }

        cout << ans << "\n";
    }
    return 0;
}
