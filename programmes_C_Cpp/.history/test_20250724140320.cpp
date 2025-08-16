#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    // 1) 先生成足够大的斐波那契数列
    vector<ll> F = {0, 1, 1};
    while(F.back() <= N) {
        F.push_back(F[F.size()-1] + F[F.size()-2]);
    }
    int k = (int)F.size() - 1;  // F[k] > N

    // 2) Zeckendorf 分解：从大到小贪心
    vector<int> b(k+1, 0);
    ll rem = N;
    for(int j = k; j >= 2; --j){
        if(F[j] <= rem){
            b[j] = 1;
            rem -= F[j];
        }
    }

    // 3) 构造 (k+1) x (k+1) 矩阵
    int n = k + 1;
    vector<vector<int>> A(n, vector<int>(n, 0));

    // 填前 k 行
    for(int i = 0; i < k; ++i){
        A[i][i] = 1;
        A[i][i+1] = 1;
        if(i+2 < n) A[i][i+2] = 1;
    }
    // 填最后一行
    A[k][0] = 1;
    for(int j = 2; j <= k-1; ++j){
        A[k][j] = b[j];
    }
    A[k][k] = 1;

    // 输出
    cout << n << "\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << A[i][j] << (j+1<n ? ' ' : '\n');
        }
    }
    return 0;
}
