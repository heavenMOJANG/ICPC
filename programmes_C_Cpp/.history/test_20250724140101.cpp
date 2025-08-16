#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    // extract binary digits b[0..k-1], with b[k-1]=1
    vector<int> b;
    while(N > 0){
        b.push_back(N & 1);
        N >>= 1;
    }
    int k = b.size();       // number of bits
    int n = k + 1;          // matrix size

    // prepare n x n matrix of 0s
    vector<vector<int>> A(n, vector<int>(n, 0));

    // fill the "upper Hessenberg" part
    for(int i = 0; i < k; i++){
        A[i][i] = 1;
        A[i][i+1] = 1;
    }

    // fill the last row
    A[k][0] = 1;
    for(int j = 0; j < k-1; j++){
        A[k][j+1] = b[j];
    }
    A[k][k] = 1;

    // output
    cout << n << "\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << A[i][j] << (j+1<n?' ':'\n');
        }
    }
    return 0;
}
