#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 计算 span = D 时的最小强度
int cost_of(ll D) {
    if (D <= 1) return 0;
    int b = 64 - __builtin_clzll(D) - 1;
    if ((D & (D-1)) != 0) ++b;
    return b - 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<ll> X(N);
    for(int i = 0; i < N; i++) cin >> X[i];
    sort(X.begin(), X.end());

    if (M >= N) {
        cout << 0 << "\n";
        return 0;
    }

    // 1) 计算相邻差
    vector<ll> gaps;
    gaps.reserve(N-1);
    for(int i = 0; i + 1 < N; i++) {
        gaps.push_back(X[i+1] - X[i]);
    }
    // 2) 取最大的 M-1 个差值作为切点
    nth_element(gaps.begin(), gaps.begin() + (M-1), gaps.end(), greater<ll>());
    sort(gaps.begin(), gaps.begin() + (M-1), greater<ll>());

    // 3) 标记这些差的位置，形成 M 段
    //    我们只需要知道每段的两端坐标，依次求 cost 即可。
    vector<int> cuts;
    cuts.reserve(M-1);
    // 重新遍历一次 gaps，收集值在前 M-1 名的那些下标
    multiset<ll, greater<ll>> topg(gaps.begin(), gaps.begin() + (M-1));
    for(int i = 0; i + 1 < N; i++) {
        auto it = topg.find(X[i+1] - X[i]);
        if (it != topg.end()) {
            cuts.push_back(i);
            topg.erase(it);
        }
    }
    sort(cuts.begin(), cuts.end());

    // 4) 逐段计算 cost
    ll answer = 0;
    int prev = 0;
    for(int idx : cuts) {
        answer += cost_of(X[idx] - X[prev]);
        prev = idx + 1;
    }
    // 最后一段
    answer += cost_of(X[N-1] - X[prev]);

    cout << answer << "\n";
    return 0;
}
