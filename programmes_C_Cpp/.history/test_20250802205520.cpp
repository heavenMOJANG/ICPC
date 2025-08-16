#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int>P(N), A(N), B(N);
    for(int i=0;i<N;i++){
        cin >> P[i] >> A[i] >> B[i];
    }

    // map: key = segment 左端点 L,
    //      val = pair(a,b) 表示 f(m)=a*m+b 在 [L, next_L-1]
    map<ll, pair<ll,ll>> seg;
    seg[0] = {1,0};   // f(m)=m  on [0..∞)

    for(int i=0; i<N; i++){
        int p = P[i], a_inc = A[i], b_dec = B[i];
        map<ll, pair<ll,ll>> nxt;

        // 把每一段都拆成最多 3 部分，然后更新
        for(auto it = seg.begin(); it != seg.end(); ++it){
            ll L = it->first;
            auto [a, b] = it->second;
            // 计算本段的 R：下一个 key - 1，或 ∞
            auto it2 = next(it);
            ll R = (it2==seg.end() ? INF : it2->first - 1);

            if(a==1){
                // 原心情 = m+b
                // happy if m+b <= p  ⇒ m <= p-b
                ll t0 = p - b;
                // 1) [L .. min(R,t0)] : 开心 → f'(m) = m + (b + a_inc)
                if(L <= t0){
                    ll r1 = min(R, t0);
                    nxt[L] = {1, b + a_inc};
                }
                // 2) [max(L,t0+1) .. R] : 失望 → 看 m+b < b_dec 还是 ≥b_dec
                ll dL = max(L, t0+1);
                if(dL <= R){
                    // 如果 m+b < b_dec ⇒ m < b_dec - b  ⇒ 变 0
                    ll t1 = b_dec - b - 1;
                    if(dL <= t1){
                        nxt[dL] = {0, 0};
                    }
                    ll d2L = max(dL, t1+1);
                    if(d2L <= R){
                        // 否则 m+b-b_dec >0 ⇒ f'(m)=m + (b - b_dec)
                        nxt[d2L] = {1, b - b_dec};
                    }
                }

            } else {
                // a==0, 原心情恒定 b
                if(b <= p){
                    // 始终开心
                    nxt[L] = {0, b + a_inc};
                } else {
                    // 始终失望
                    ll nb = max(0LL, b - b_dec);
                    nxt[L] = {0, nb};
                }
            }
        }

        // 合并相邻相同 (a,b)
        seg.clear();
        for(auto [L, ab] : nxt){
            if(seg.empty()){
                seg[L] = ab;
            } else {
                auto it = prev(seg.end());
                if(it->second == ab){
                    // 不要插新的 key，只保留旧的 L，合并区间自然连上
                } else {
                    seg[L] = ab;
                }
            }
        }
    }

    // 处理查询
    int Q;
    cin >> Q;
    while(Q--){
        ll x;
        cin >> x;
        // 找最大的 key <= x
        auto it = seg.upper_bound(x);
        --it;
        auto [a, b] = it->second;
        ll ans = a ? x + b : b;
        cout << ans << "\n";
    }
    return 0;
}
