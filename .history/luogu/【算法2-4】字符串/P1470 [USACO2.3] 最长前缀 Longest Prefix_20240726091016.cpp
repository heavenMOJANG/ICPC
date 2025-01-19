#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 2010, M = 200010;
string s;
int trie[N][26], e[N], fail[N], cnt;
void insert(string str) {
    int u = 0, len = str.size();
    for (int i = 0; i < len; ++ i) {
        int c = str[i] -'A';
        if(!trie[u][c]) trie[u][c] = ++ cnt;
        u = trie[u][c];
    }
    e[u] = len;
}
void getFail() {
    queue<int> q;
    for (int i = 0; i < 26; ++ i) if(trie[0][i]) q.push(trie[0][i]);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < 26; ++ i) {
            if (trie[u][i]) {
                fail[trie[u][i]] = trie[fail[u]][i];
                q.push(trie[u][i]);
            } else trie[u][i] = trie[fail[u]][i];
        }
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    while(cin >> s && s[0] != '.') {
        insert(s);
    }
    return 0;
}