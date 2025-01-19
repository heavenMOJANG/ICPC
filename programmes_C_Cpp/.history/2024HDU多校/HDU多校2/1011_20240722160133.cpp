#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 0x7fffffff;
typedef deque<int> dic;
const int N = 2e5 + 10;

void solve(){
    char s0[N],s1[N],t0[N],t1[N];
    int n,cnt,vis[N],ans,in[N],Map[N];
    struct ACM{
        int son[26],fail,flag,ans;
        void clear(){
		    memset(son, 0, sizeof(son));
		    fail = flag = ans = 0;
	    }
    }trie[N];
    queue<int>q;
    function<void(char*, int)> insert=[&](char *s,int num){
        int u = 1,len = strlen(s);
        for (int i = 0;i < len; ++ i){
            int v = s[i] - 'a';
            if(!trie[u].son[v]) trie[u].son[v] = ++cnt;
            u = trie[u].son[v];
        }
        if (!trie[u].flag) trie[u].flag = num;
        Map[num] = trie[u].flag;
    }
    void getFail(){
        for (int i = 0; i < 26; ++ i) trie[0].son[i] = 1;
        q.push(1);
        while (!q.empty()){
            int u = q.front(); q.pop();
            int Fail = trie[u].fail;
            for(int i = 0; i < 26; ++ i){
                int v = trie[u].son[i];
                if (!v) {trie[u].son[i] = trie[Fail].son[i]; continue;}
                trie[v].fail = trie[Fail].son[i]; in[trie[v].fail] ++;
                q.push(v);
            }
        }
    }
    void topu(){
        for(int i = 1; i <= cnt; ++ i)
        if (in[i] == 0) q.push(i);
        while(!q.empty()){
            int u = q.front(); q.pop();
		    vis[trie[u].flag] = trie[u].ans;
            int v = trie[u].fail; in[v] --;
            trie[v].ans += trie[u].ans;
            if(in[v] == 0) q.push(v);
        }
    }
    void query(char* s){
        int u=1,len = strlen(s);
        for(int i = 0;i < len; ++ i)
        u = trie[u].son[s[i] - 'a'],trie[u].ans ++;
    }
    cin >> n;
    cin >> t0 >> t1;
    for(int i = 1;i <= n; ++ i){
        cin >> s0 >> s1;
        insert(s0, i);
    }
    getFail();
    query(t0);
    topu();
    vector<int>ans;
    for (int i = 1; i <= n; ++ i)
        if (vis[Map[i]]) ans.push_back(i);
    for (int i = 1; i < ans.size() -  1; ++ i) cout << ans[i] << " "[i == ans.size() - 1];
    cout<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}