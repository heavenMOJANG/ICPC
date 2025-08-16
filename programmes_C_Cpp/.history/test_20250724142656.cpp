#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void print_matrix(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) return;
    int n = matrix.size();
    std::cout << n << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << (j == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    if (N == 1) {
        std::cout << 1 << std::endl;
        std::cout << 1 << std::endl;
        return 0;
    }

    int k = 0;
    if (N > 1) {
       k = floor(log2(N -1)) + 1;
    }
    if (N == 2) k = 1;


    int n = k;
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 0));
    
    int M = N;

    for(int i = 0; i < n - 1; ++i) {
        A[i][i] = 1;
        A[i+1][i] = 1;
    }
    
    int temp_M = M;
    for(int i = 0; i < n; ++i){
        if((temp_M >> i) & 1){
            A[i][n-1] = 1;
        }
    }
    
    if ( M % 2 == 0) {
        A[n-1][n-1] = 1;
    }


    print_matrix(A);

    return 0;
}