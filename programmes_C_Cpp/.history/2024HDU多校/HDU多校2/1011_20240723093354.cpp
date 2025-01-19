#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N = 5e5 + 10, mod1 = 998244353, mod2 = 19260817, p = 131;
int n, cnt, trie[N][26], fail[N], in[N], match[N], vis[N], rec[N], nxt[10010];
int a1[N], a2[N], hs1[N], hs2[N], hs3[N], hs4[N];
vector<int> g[N];
void init(){
	a1[0] = a2[0] = 1;
	for (int i = 1;i < N; ++ i) {
		a1[i] = a1[i - 1] * p % mod1;
		a2[i] = a2[i - 1] * p % mod2;
	}
}
void hashstr1(string &str){
	int n = str.size();
	for(int i = 1; i <= n; ++ i){
		hs1[i] = (hs1[i - 1] * p % mod1 + str[i - 1]) % mod1;
		hs2[i] = (hs2[i - 1] * p % mod2 + str[i - 1]) % mod2;
	}
}
int insert(const string &str) {
	int cur = 0;
	for (int i = 0; i < str.size(); ++ i) {
		int c = str[i] - 'a';
		if (!trie[cur][c])
			trie[cur][c] = ++ cur;
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
}
void query(string x) {
	int len = x.length (), now = 0;
	for (int i = 0; i < len; i++) {
		int c = x[i] - 'a';
		now = trie[now][c];
		vis[now] ++;
	}
}
void topu() {
	queue <int> q;
	for(int i = 1; i <= cnt; i++)
		if(!in[i])
			q.push(i);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = fail[x];
		in[y]--;
		vis[y] += vis[x];
		if(!in[y])
			q.push(y);
	}
}

void init(){
    memset(trie, 0, sizeof(trie));
    fill(fail, fail + N, 0);
    fill(in, in + N, 0);
    fill(vis, vis + N, 0);
    fill(rec, rec + N, 0);
    fill(match, match + N, 0);
    cnt = 0;
}
void solve(){
    init();
    cin >> n;
    string a, c; cin >> a >> c;
    vector<int> vv(n + 1);
    for(int i = 1;i <= n; ++ i){
        string b, bb;
        cin >> b >> bb;
        insert(b, i);
    }
    getFail();
    query(a);
    topu();
    vector<int>ans;
    for (int i = 1; i <= n; ++ i)
        if (vis[match[i]] && vv[i]) ans.emplace_back(i);
    for (int i = 0; i < ans.size(); ++ i) cout << ans[i] << " "[i == ans.size() - 1];
    cout<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}