#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
string s[1010],t[110];
int trie[1010][26],fail[1010],rec[1010][1010],idx;
vector<int>v[1010];
void _insert(string&s,int&id){
    int cur=0;
    for(int i=0;i<s.size();++i){
        if(!trie[cur][s[i]-'a']){
            trie[cur][s[i]-'a']=++idx;
            v[trie[cur][s[i]-'a']].clear();
        }
        cur=trie[cur][s[i]-'a'];
    }
    v[cur].push_back(id);
}
void getFail(){
    queue<int>q;
    fail[0]=0;
    for(int i=0;i<26;++i)
        if(trie[0][i]){
            q.push(trie[0][i]);
            fail[trie[0][i]]=0;
        }
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int i=0;i<26;++i)
            if(trie[cur][i]) q.push(trie[cur][i]),fail[trie[cur][i]]=trie[fail[cur]][i];
            else trie[cur][i]=trie[fail[cur]][i];
    }
}
void cal(int&k,int&len){
    int cur=0;
    for(int i=0;i<s[k].size();++i){
        cur=trie[cur][s[k][i]-'a'];
        for(int j=cur;j;j=fail[j])
            for(int w=0;w<v[j].size();++w){
                if(k-v[j][k]<0||i-len+1<0) continue;
                rec[k-v[j][w]][i-len+1]++;
            }
    }
    return;
}
int query(int&m,int&n,int&x,int&y){
    int res=0;
    for(int i=0;i+x-1<m;++i)
        for(int j=0;j+y-1<n;++j) res+=(rec[i][j]==x);
    return res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--){
        memset(trie,0,sizeof trie);
        memset(fail,0,sizeof fail);
        memset(rec,0,sizeof rec);
        idx=0;v[0].clear();
        int m,n;cin>>m>>n;
        for(int i=0;i<m;++i) cin>>s[i];
        int x,y;cin>>x>>y;
        for(int i=0;i<x;++i) cin>>t[i],_insert(t[i],i);
        getFail();
        for(int i=0;i<m;++i) cal(i,y);
        cout<<query(m,n,x,y)<<"\n";
    };
    return 0;
}
