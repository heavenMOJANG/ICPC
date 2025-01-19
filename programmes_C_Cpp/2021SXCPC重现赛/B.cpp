#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,q,m,sum;
struct Node{
    ll a,b,d,id;
    bool operator>(const Node&x)const{return d>x.d;}
}g[100010];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(ll i=1;i<=n;++i) cin>>g[i].a,g[i].id=i,sum+=g[i].a;
    for(ll i=1;i<=n;++i) cin>>g[i].b,g[i].d=g[i].b-g[i].a;
    sort(g+1,g+1+n,greater<Node>());
    cin>>q;
    while(q--){
        cin>>m;
        set<ll>s;
        for(ll i=1,x;i<=m;++i) cin>>x,s.insert(x);
        ll cnt=0,p=1,res=0;
        while(p<=n){
            if(s.find(g[p].id)==s.end()) res+=g[p].d,cnt++,p++;
            else{p++;continue;}
            if(cnt==k) break;
        }
        cout<<sum+res<<"\n";
    }
    return 0;
}