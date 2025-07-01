#include<bits/stdc++.h>
#define int long long
using namespace std;
mt19937_64 rnd;
signed main(){
    cout.tie() -> sync_with_stdio(0);
    int n = 10;
    vector<int> a(2 * n);
    iota(a.begin(), a.end(), 1);
    int cnt{}, flag = 114;
    do {
        if (cnt == flag) break;
        cnt ++;
    } while (next_permutation(a.begin(), a.end()));
    for (int i{}; i < n; ++ i) cout << a[i] << " \n"[i == n - 1];
    return 0;
}
