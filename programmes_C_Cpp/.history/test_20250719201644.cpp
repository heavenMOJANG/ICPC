#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;
    vector<pair<ll,ll>> exchanges;
    exchanges.reserve(M);

    for (int i = 0; i < M; i++) {
        ll A, B;
        cin >> A >> B;
        // 初期空き瓶 N で一度もできない交換は無視
        if (A <= N) {
            // コスト C = A - B, 閾値 A
            exchanges.emplace_back(A - B, A);
        }
    }

    // コスト昇順ソート
    sort(exchanges.begin(), exchanges.end());

    ll E = N;  // 現在の空き瓶数
    ll ans = 0;  // 獲得シール枚数

    for (auto &p : exchanges) {
        ll C = p.first;
        ll A = p.second;
        if (E < A) continue;
        // まとめて k 回交換
        ll k = (E - A) / C + 1;
        ans += k;
        E -= k * C;
    }

    cout << ans;
    return 0;
}
