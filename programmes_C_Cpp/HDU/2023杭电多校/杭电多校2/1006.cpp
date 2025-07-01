#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
struct Node{ll x,y;}a[510],b[510];
ll _,n,m,g[510][510],minn=inf;
class Solution{
public:
    ll check(Node a,Node b,Node c){return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);}
    void main(){
        cin>>_;
        while(_--){
            cin>>n>>m;
            for(ll i=1;i<=n;++i) cin>>a[i].x>>a[i].y;
            for(ll i=1;i<=m;++i) cin>>b[i].x>>b[i].y;
            for(ll i=1;i<=n;++i)
                for(ll j=1;j<=n;++j){
                    g[i][j]=inf;
                    if(i!=j){
                        g[i][j]=1;
                        for(ll k=1;k<=m;++k) if(check(a[i],a[j],b[k])<=0) g[i][j]=inf;
                    }
                }
            for(ll k=1;k<=n;++k)
                for(ll i=1;i<=n;++i)
                    for(ll j=1;j<=n;++j) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            minn=inf;
            for(ll i=1;i<=n;++i) minn=min(minn,g[i][i]);
            if(minn==inf) minn=-1LL;
            cout<<minn<<"\n";
        }
    }
};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution solution;
    solution.main();
    return 0;
}
