#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=500010;
int n,m,ch[N][26],tag[N],idx=1;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i){
        string s;cin>>s;
        int u=1;
        for(auto chr:s){
            int c=chr-'a';
            if(!ch[u][c]) ch[u][c]=++idx;
            u=ch[u][c];
        }
        tag[u]=1;
    }
    cin>>m;
    while(m--){
        string s;cin>>s;
        int u=1;
        for(auto chr:s){
            int c=chr-'a';
            u=ch[u][c];
            if(!u) break;
        }
        if(tag[u]==1){
            tag[u]=2;
            cout<<"OK\n";
        }
        else if(tag[u]==2) cout<<"REPEAT\n";
        else cout<<"WRONG\n";
    }
    return 0;
}