#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Node{string name;ll rnk,cst;};
ll n,m;
vector<Node>res;
map<string,ll>v1,v2,v;
void solve(){
    cin>>n>>m;
    ll rnk=0;
    for(ll i=1;i<=n;++i){
        string s;cin>>s;
        if(v1.find(s)!=v1.end()) continue;
        res.push_back({s,++rnk,1});
        v1[s]=1;
    }
    rnk=0;
    for(ll i=1;i<=m;++i){
        string s;cin>>s;
        if(v2.find(s)!=v2.end()) continue;
        res.push_back({s,++rnk,2});
        v2[s]=1;
    }
    sort(res.begin(),res.end(),[](Node x,Node y){return x.rnk==y.rnk?x.cst<y.cst:x.rnk<y.rnk;});
    for(Node ans:res){
        if(v.find(ans.name)!=v.end()) continue;
        cout<<ans.name<<"\n";
        v[ans.name]=1;
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
