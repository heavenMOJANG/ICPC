#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int dx[]={-1,1,0,0};
constexpr int dy[]={0,0,-1,1};
void solve(){
    int n;cin>>n;
    string g[2];cin>>g[0]>>g[1];
    vector<vector<int>>v(2,vector<int>(n,0));
    queue<pair<int,int>>q;
    q.push({0,0});v[0][0]=1;
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int tx=x+dx,ty=y+ty;
            if(tx<0||ty<0||tx>1||ty>n-1) continue;
            if(g[tx][ty]=='<') ty--;
            else ty++;
            if(!v[tx][ty]){
                v[tx][ty]=1;
                q.push({tx,ty});
            }
        }
    }
    cout<<(v[1][n-1]?"YES\n":"NO\n");
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
