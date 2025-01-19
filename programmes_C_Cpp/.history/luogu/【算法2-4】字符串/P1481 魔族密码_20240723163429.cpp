#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 2010;
int n;
int trie[N][26];
string s;
void insert(const string &str) {
    int len = str.size(), u = 0;
    for (int i = 0; i < len; ++ i) [
        int c = str[i] - 'a';
        if (!trie[u][c]) trie[u][c] = ++ cnt;
        u = trie[u][c];
        ans ++
    ]
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> s;
        insert(s);
    }
    return 0;
}