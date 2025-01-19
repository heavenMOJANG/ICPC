#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
typedef std::deque<int> dic;
const int N = 1e5+10;
int cnt[2][N];
struct ACM{
    struct Node{
        int son[30],val,fail,head;
        dic index;
    }node[N];
    struct Edge{
        int head;
        int next;
    }edge[N];
    int root;
    int ncnt;
    int ecnt;
    void Insert(string str, int i) {
        int u = root;
        for (int i = 1; str[i]; i++) {
            if (node[u].son[str[i] - 'a' + 1] == 0)
            node[u].son[str[i] - 'a' + 1] = ++ncnt;
            u = node[u].son[str[i] - 'a' + 1];
        }
        node[u].index.push_back(i);
        return;
    }
    void Build() {
        dic q;
        for (int i = 1; i <= 26; i++)
        if (node[root].son[i]) q.push_back(node[root].son[i]);
        while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (int i = 1; i <= 26; i++) {
            if (node[u].son[i]) {
            node[node[u].son[i]].fail = node[node[u].fail].son[i];
            q.push_back(node[u].son[i]);
            } else {
            node[u].son[i] = node[node[u].fail].son[i];
            }
        }
        }
        return;
    }
    void Query(string str) {
        int u = root;
        for (int i = 1; str[i]; i++) {
        u = node[u].son[str[i] - 'a' + 1];
        node[u].val++;
        }
        return;
    }
    void addEdge(int tail, int head) {
        ecnt++;
        edge[ecnt].head = head;
        edge[ecnt].next = node[tail].head;
        node[tail].head = ecnt;
        return;
    }
    void DFS(int u,int idx) {
        for (int e = node[u].head; e; e = edge[e].next) {
            int v = edge[e].head;
            DFS(v,idx);
            node[u].val += node[v].val;
        }
        for (auto i : node[u].index) cnt[idx][i] += node[u].val;
        return;
    }
    void FailTree(int idx) {
        for (int u = 1; u <= ncnt; u++) addEdge(node[u].fail, u);
        DFS(root,idx);
        return;
    }
};
void solve(){
    ACM acm[2];
    int n;cin >> n;
    string s[2],t[2];cin >> t[0] >> t[1];
    t[0]=" " + t[0];
    t[1] = " " + t[1];
    fill(cnt[0], cnt[0] + 1 + n, 0);
    fill(cnt[1], cnt[1] + 1 + n, 0);
    for(int i = 1;i <= n; ++ i){
        cin >> s[0] >> s[1];
        s[0] = " " + s[0];
        s[1] = " " + s[1];
        acm[0].Insert(s[0],i);
        acm[1].Insert(s[1],i);
    }
    acm[0].Build();acm[1].Build();
    acm[0].Query(t[0]);acm[1].Query(t[1]);
    acm[0].FailTree(0);acm[1].FailTree(1);
    vector<int>ans;
    for (int i = 1; i <= n; ++ i) if(cnt[0][i] && cnt[1][i]) ans.emplace_back(i);
    for (int i = 1; i < ans.size() -  1; ++ i) cout << ans[i] << " \n"[i == ans.size() - 1];
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}