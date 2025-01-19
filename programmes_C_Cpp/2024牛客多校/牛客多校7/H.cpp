#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int n, q;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    vector<string> fieldName(n);
    for (int i = 0; i < n; ++ i) cin >>fieldName[i];
    string operation;
    while (q -- ) {
        cin >> operation;
        if (operation == "begin()") continue;
    }
    return 0;
}