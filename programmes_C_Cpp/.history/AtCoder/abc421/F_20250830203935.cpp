#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int Q;
vector<int> L, R, P, siz, acc, pri, val;
int rt = -1;
int getSiz(int x) { return x == -1 ? 0ll : siz[x]; }
int getAcc(int x) { return x == -1 ? 0ll : acc[x]; }
void insert(int p) {
    if (p == -1) return;
    siz[p] = 
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    return 0;
}