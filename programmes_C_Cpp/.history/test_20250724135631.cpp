#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    // 1) Compute binary length k = floor(log2 N)
    int k = 0;
    while ((1LL << (k+1)) <= N) ++k;

    int n = k + 2;               // matrix size
    vector<vector<int>> A(n, vector<int>(n, 0));

    // 2) Diagonal = 1
    for(int i = 0; i < n; i++){
        A[i][i] = 1;
    }
    // 3) Super‑diagonal = 1
    for(int i = 0; i + 1 < n; i++){
        A[i][i+1] = 1;
    }
    // 4) Last row encodes bits b_i
    for(int i = 0; i <= k; i++){
        if ( (N >> i) & 1LL ){
            // bit i is 1 -> set A[n-1][ (n-1)-1 - i ] = 1
            A[n-1][n-2 - i] = 1;
        }
    }

    // Output
    cout << n << "\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << A[i][j] << (j+1<n ? ' ' : '\n');
        }
    }
    return 0;
}
