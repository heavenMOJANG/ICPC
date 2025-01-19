#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N = 5e5 + 10, mod1 = 998244353, mod2 = 19260817, p = 131;
int n, cnt, trie[N][26], fail[N], sum[N], e[N];
int a1[N], a2[N], hs1[N], hs2[N];
vector<int> g[N];
void init() {
	a1[0] = a2[0] = 1;
	for (int i = 1;i < 2e5 + 10; ++ i) {
		a1[i] = 1ll * a1[i - 1] * p % mod1;
		a2[i] = 1ll * a2[i - 1] * p % mod2;
	}
}
void getHash(string &str) {
	int len = str.size();
	for(int i = 1; i <= len; ++ i){
		hs1[i] = (1ll * hs1[i - 1] * p % mod1 + str[i - 1]) % mod1;
		hs2[i] = (1ll * hs2[i - 1] * p % mod2 + str[i - 1]) % mod2;
	}
}
int getHash1(int l, int r) {
	return (hs1[r] - hs1[l - 1] * a1[r - l + 1] % mod1 + mod1) % mod1;
}
int getHash2(int l, int r) {
	return (hs2[r] - hs2[l - 1] * a2[r - l + 1] % mod2 + mod2) % mod2;
}
int insert(const string &str) {
	int cur = 0;
	for (int i = 0; i < str.size(); ++ i) {
		int c = str[i] - 'a';
		if (!trie[cur][c]) trie[cur][c] = ++ cnt;
		cur = trie[cur][c];
	}
	return cur;
}
void getFail() {
	queue<int> q;
	for (int i = 0; i < 26; ++ i)
		if (trie[0][i]) q.push(trie[0][i]);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; ++ i) {
			if (trie[u][i]) {
				fail[trie[u][i]] = trie[fail[u]][i];
				q.push (trie[u][i]);
			} else trie[u][i] = trie[fail[u]][i];
		}
	}
    for(int i = 1; i <= cnt; ++ i) g[fail[i]].emplace_back(i);
}
void dfs(int u) {
    for (auto v : g[u]) {
        dfs(v);
        sum[v] += sum[u];
    }
}

void solve(){
    cin >> n;
    string a, c; cin >> a >> c;
    vector<string> b(n + 1), _b(n + 1);
    int hashC1 = 0, hashC2 = 0;
    for (int i = 0; i < c.size(); ++ i) {
        hashC1 = (1ll * hashC1 * p % mod1 + c[i]) % mod1;
        hashC2 = (1ll *hashC2 * p % mod2 + c[i]) % mod2;
    }
    for (int i = 1; i <= n; ++ i) {
        cin >> b[i] >> _b[i];
        getHash(_b[i]);
        int flag = 0;
        for (int j = 0; j + c.size() - 1 < _b[i].size(); ++ j)
            if (make_pair(hashC1, hashC2) == make_pair(getHash1(j + 1, j + c.size()), getHash2(j + 1, j + c.size()))) {
                flag = 1;
                break;
            }
        if (flag) e[i] = insert(b[i]);
    }
    getFail();
    int u = 0;
    for (int i = 0; i < a.size(); ++ i) {
        int d = a[i] - 'a';
        u = trie[u][d];
        sum[u] ++;
    }
    dfs(0);
    vector<int> ans;
    for (int i = 1; i <= n; ++ i) if(e[i] && sum[e[i]]) ans.emplace_back(i);
    for (int i = 0; i < ans.size(); ++ i) cout << ans[i] << " \n"[i == ans.size() - 1];
    if (ans.empty()) cout << "\n";
    for (int i = 1; i <= n; ++ i) e[i] = 0;
    for (int i = 1; i <= cnt; ++ i) {
        memset(trie[i], 0, sizeof(trie[i]));
        fail[i] = sum[i] = 0;
        g[i].clear();
        g[i].shrink_to_fit();
    }
    cnt = 0;
    return;
}
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    init();
    int _ = 1;cin >> _;
    while(_ --) solve();
    return 0;
}