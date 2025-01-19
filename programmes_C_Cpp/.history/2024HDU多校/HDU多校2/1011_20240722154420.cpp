#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
typedef std::deque<int> dic;
const int N = 1e5+10;
char s0[N],s1[N],T0[N],T1[N];
int n,cnt,vis[N],ans,in[N],Map[N];
struct ACM{
    int son[26],fail,flag,ans;
    void clear(){memset(son,0,sizeof(son)),fail=flag=ans=0;}
}trie[N];
queue<int>q;
void insert(char *s,int num){
    int u=1,len=strlen(s);
    for(int i=0;i<len;i++){
        int v=s[i]-'a';
        if(!trie[u].son[v])trie[u].son[v]=++cnt;
        u=trie[u].son[v];
    }
    if(!trie[u].flag)trie[u].flag=num;
    Map[num]=trie[u].flag;
}
void getFail(){
    for(int i=0;i<26;i++)trie[0].son[i]=1;
    q.push(1);
    while(!q.empty()){
        int u=q.front();q.pop();
        int Fail=trie[u].fail;
        for(int i=0;i<26;i++){
            int v=trie[u].son[i];
            if(!v){trie[u].son[i]=trie[Fail].son[i];continue;}
            trie[v].fail=trie[Fail].son[i]; in[trie[v].fail]++;
            q.push(v);
        }
    }
}
void topu(){
    for(int i=1;i<=cnt;i++)
    if(in[i]==0)q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();vis[trie[u].flag]=trie[u].ans;
        int v=trie[u].fail;in[v]--;
        trie[v].ans+=trie[u].ans;
        if(in[v]==0)q.push(v);
    }
}
void query(char* s){
    int u=1,len=strlen(s);
    for(int i=0;i<len;i++)
    u=trie[u].son[s[i]-'a'],trie[u].ans++;
}
void solve(){
    int n;cin >> n;
    string s[2],t[2];cin >> t[0] >> t[1];
    for(int i = 1;i <= n; ++ i){
        cin >> s[0] >> s[1];
        if(s[0].size()<=t[0].size()) insert(s0,i);
    }
    getFail();
    vector<int>ans;
    for (int i = 1; i <= n; ++ i) if(vis[Map[i]]) ans.emplace_back(i);
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