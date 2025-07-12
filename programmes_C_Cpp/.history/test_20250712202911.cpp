#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    // 如果基站数 >= 房子数，全部强度 0
    if (M >= N) {
        cout << 0 << "\n";
        return 0;
    }

    // 计算相邻差分
    vector<ll> gaps;
    gaps.reserve(N-1);
    for(int i = 0; i < N-1; i++){
        gaps.push_back(X[i+1] - X[i]);
    }

    // 取 M-1 个最大的 gap 断开
    sort(gaps.begin(), gaps.end(), greater<ll>());

    ll S = 0;
    for(int i = 0; i < M-1; i++){
        S += gaps[i];
    }

    // 总跨度减去这 M-1 段
    ll answer = (X[N-1] - X[0]) - S;
    cout << answer << "\n";
    return 0;
}
