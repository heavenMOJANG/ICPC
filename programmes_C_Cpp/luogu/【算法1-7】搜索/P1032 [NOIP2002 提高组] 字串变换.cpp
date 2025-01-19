#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
struct Node{
    string x;
    ll step;
};
ll idx,step; 
string n,m,a[1010],b[1010];
map<string,ll>vis; 
ll bfs(){
    queue<Node>q;
    q.push({n,0});
    while(!q.empty()){
        Node u=q.front();q.pop();
        if(u.x==m){cout<<u.step<<"\n";return 1;}
        if(u.step>10) return 0;
        for(ll i=0;i<idx;++i){
            string tmp=u.x;
            ll pos=tmp.find(a[i]);
            while(pos!=string::npos){
                tmp.replace(pos,a[i].size(),b[i]); 
                if(!vis[tmp]){
                    q.push({tmp,u.step+1});
                    vis[tmp]=1;
                }
                tmp=u.x; 
                pos=tmp.find(a[i],pos+1);
            }
        } 
    }
    return 0;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    while(cin>>a[idx]>>b[idx]) idx++;
    if(!bfs()) cout<<"NO ANSWER!\n";
    return 0;
}