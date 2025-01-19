#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 1e6 + 10;
int n, nxt[N];
string s;
void getNext(const string & str) {
    nxt[0] = 0; nxt[1] = 0;
    for (int i = 1; i < str.size(); ++ i) {
        int j = nxt[i];
        while(j && str[i] != str[j]) j = nxt[j];
        if (str[i] == str[j]) nxt[i + 1] = j + 1;
        else nxt[j + 1] = 0;
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> s;
    getNext(s);
    cout << n - nxt[n] << "\n";
    return 0;
}