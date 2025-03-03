#include<bits/stdc++.h>
using namespace std;
int main() {
    for (int i = 192; i <= 333; ++ i)
        for (int j = 384; j <= 666; ++ j)
            for (int k = 576; k <= 999; ++ k) {
                int i0 = i / 100, i1 = i / 10 % 10, i2 = i % 10;
                int j0 = j / 100, j1 = j / 10 % 10, j2 = j % 10;
                int k0 = k / 100, k1 = k / 10 % 10, k2 = k % 10;
                if (i0 + i1 + i2 + j0 + j1 + j2 + k0 + k1 + k2 != 45) continue;
                if (i0 * i1 * i2 * j0 * j1 * j2 * k0 * k1 * k2 != 362800) continue;
                //if (i * 2 != j || j * 3 != k * 2) continue;
                cout << i << " " << j << " " << k << endl;
            }
    return 0;
}