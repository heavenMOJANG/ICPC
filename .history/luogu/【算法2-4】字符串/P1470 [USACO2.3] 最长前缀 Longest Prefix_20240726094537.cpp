#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 2010, M = 200010;
string s;
int trie[N][26], e[N], fail[N], cnt = 2;
int dp[M];
void insert(string str) {
    int u = 1, len = str.size();
    for (int i = 0; i < len; ++ i) {
        int c = str[i] -'A';
        if(!trie[u][c]) trie[u][c] = cnt ++;
        u = trie[u][c];
    }
    e[u] = len;
}
void getFail() {
    queue<int> q;
    for (int i = 0; i < 26; ++ i) trie[0][i] = 1;
    q.push(1);
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
void getAns(const string & str) {
    dp[0] = 1;
    int u = 1, len = str.size();
    for (int i = 1; i <= len; ++ i) {
        int c = str[i] - 'A';
        u = trie[u][c];
        for (int j = u; j && !dp[i]; j = fail[j]) {
            if (e[j]) dp[i] |= dp[i - e[j]];
        }
    }
    for (int i = len - 1; i >= 0; -- i)
        if (dp[i]) {cout << i << "\n"; return;}
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    while(cin >> s && s[0] != '.') {
        insert(s);
    }
    getFail();
    cin >> s;
    s = " " + s;
    getAns(s);
    return 0;
}