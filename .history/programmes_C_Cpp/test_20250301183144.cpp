#include<bits/stdc++.h>
using namespace std;
int main() {
    for (int i = 111; i <= 333; ++ i)
        for (int j = 334; j <= 666; ++ j)
            for (int k = 667; k <= 999; ++ k) {
                int i0 = i / 100, i1 = i / 10 % 10, i2 = i % 10;
                int j0 = j / 100, j1 = j / 10 % 10, j2 = j % 10;
                int k0 = k / 100, k1 = k / 10 % 10, k2 = k % 10;
                if ((i0 + i1 + i2 + j0 + j1 + j2 + k0 + k1 + k2 == 45) && (i0 * i1 * i2 * j0 * j1 * j2 * k0 * k1 * k2 == 362800))
                    cout << i << " " << j << " " << k << endl;
            }
    return 0;
}