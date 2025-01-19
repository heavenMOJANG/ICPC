#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
struct Node {
    int sum, l, r;
}t[N << 5];
int n, m, idx = 1,rt[N << 2], rub[N << 5], cnt, tot;
int _new() {
    return cnt ? rub[cnt --] : ++ tot;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    return 0;
}