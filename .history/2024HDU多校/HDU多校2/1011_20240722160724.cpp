#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
typedef std::deque<int> dic;
const int N = 2e5+10;
int n, trie[N][26], fail[N], cnt, in[N], vis[N], ans[N];
vector <int> flag[N];

void insert (string x, int id) { //建trie树
	int len = x.length (), now = 0;
	for (int i = 0; i < len; i++) {
		int c = x[i] - 'a';
		if (!trie[now][c])
			trie[now][c] = ++cnt;
		now = trie[now][c];
	}
	flag[now].push_back (id);
}

void getFail () { //添加fail边
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
				in[fail[trie[u][i]]]++; //fail边指向的点入度+1
				q.push (trie[u][i]);
			}
			else trie[u][i] = trie[fail[u]][i];
		}
	}
}

void query (string x) { //查询答案
	int len = x.length (), now = 0;
	for (int i = 0; i < len; i++) {
		int c = x[i] - 'a';
		now = trie[now][c];
		vis[now]++; //不需跳fail边
	}
}

void topu () { //拓扑排序
	queue <int> q;
	for (int i = 1; i <= cnt; i++)
		if (!in[i])
			q.push (i);
	while (!q.empty ()) {
		int u = q.front ();
		q.pop ();
		for (auto it = flag[u].begin (); it != flag[u].end (); it++)
			ans[*it] = vis[u];
		int v = fail[u];
		vis[v] += vis[u];
		in[v]--;
		if (!in[v])
			q.push (v);
	}
}
void solve(){
    int n;cin >> n;
    string a,c; cin >> a >> c;
    string s[2],t[2];cin >> t[0] >> t[1];
    for(int i = 1;i <= n; ++ i){
        string b, bb;
        cin >> b >> bb;
        insert(b,i);
    }
    getFail();
    query(a);
    cout<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}