#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
struct Node {
    int l, r, h, syb;
    Node () {}
    Node (int a, int b, int c, int d) : l(a), r(b), h(c), syb(d) {}
}t[N];
int cmp (const Node & x,const Node & y) {return x.h < y.h;}
int leftOverlapped[N << 2], rightOverlapped[N << 2];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}