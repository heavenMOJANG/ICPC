#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
const int N = 1e5+10;
int n, trie[N][26], fail[N], cnt, in[N], vis[N], rec[N], nxt[N];
vector<int>flag[N];

void insert (string x, int id) {
	int len = x.length (), now = 0;
	for (int i = 0; i < len; i++) {
		int c = x[i] - 'a';
		if (!trie[now][c])
			trie[now][c] = ++cnt;
		now = trie[now][c];
	}
	flag[now].push_back (id);
}

void getFail () {
	queue <int> q;
	for (int i = 0; i < 26; i++)
		if (trie[0][i])
			q.push (trie[0][i]);
	while (!q.empty ()) {
		int u = q.front ();
		q.pop ();
		for (int i = 0; i < 26; i++) {
			if (trie[u][i]) {
				fail[trie[u][i]] = trie[fail[u]][i];
				in[fail[trie[u][i]]]++;
				q.push (trie[u][i]);
			}
			else trie[u][i] = trie[fail[u]][i];
		}
	}
}

void query (string x) {
	int len = x.length (), now = 0;
	for (int i = 0; i < len; i++) {
		int c = x[i] - 'a';
		now = trie[now][c];
		vis[now]++;
	}
}

void topu () {
	queue <int> q;
	for (int i = 1; i <= cnt; i++)
		if (!in[i])
			q.push (i);
	while (!q.empty ()) {
		int u = q.front ();
		q.pop ();
		for (auto it = flag[u].begin (); it != flag[u].end (); it++)
			rec[*it] = vis[u];
		int v = fail[u];
		vis[v] += vis[u];
		in[v]--;
		if (!in[v])
			q.push (v);
	}
}
void getNext(string p) {
    nxt[0] = 0; nxt [1] = 0;
    for(int i = 1; i < p.size(); ++ i) {
        int j = nxt[i];
        while (j && p[i] != p[j]) j = nxt[j];
        if(p[i] == p[j]) nxt[i + 1] = j + 1;
        else nxt[i + 1] = 0;
    }
}
int kmp(string s, string p) {
    int last = -1;
    int slen = s.size(), plen = p.size();
    int j = 0;
    for(int i = 0; i < slen; ++ i) {
        while(j && s[i] != p[j]) j = nxt[j];
        if(s[i] == p[j]) j ++;
        if(j == plen) return 1;
    }
    return 0;
}
void init(){
    cnt = 0;
    memset(trie, 0, sizeof(trie));
    memset(fail, 0, sizeof(fail));
    memset(in, 0, sizeof(in));
    memset(vis, 0, sizeof(vis));
    memset(rec, 0, sizeof(rec));
    cnt = 0;
    for(int i = 0; i < N; ++ i) flag[i].clear();
}
void solve(){
    init();
    int n;cin >> n;
    string a,c; cin >> a >> c;
    getNext(c);
    vector<int> vv(n + 1);
    for(int i = 1;i <= n; ++ i){
        string b, bb;
        cin >> b >> bb;
        insert(b,i);
        vv[i] = kmp(bb, c);
    }
    getFail();
    query(a);
    topu();
    vector<int>ans;
    for (int i = 1; i <= n; ++ i)
        if (rec[i] >= 1 && vv[i]) ans.emplace_back(i);
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