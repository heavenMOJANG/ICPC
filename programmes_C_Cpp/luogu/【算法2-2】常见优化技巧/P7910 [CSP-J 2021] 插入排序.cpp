#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Node{
    ll id,val;
    
}a[8010];
ll n,q,b[8010];
ll cmp(Node x,Node y){return x.val==y.val?x.id<y.id:x.val<y.val;}
void solve(){
    cin>>n>>q;
    for(ll i=1;i<=n;++i) cin>>a[i].val,a[i].id=i;
    sort(a+1,a+1+n,cmp);
    for(ll i=1;i<=n;++i) b[a[i].id]=i;
    while(q--){
        ll op,x,v;
        cin>>op;
        if(op==1){
            cin>>x>>v;
            a[b[x]].val=v;
            for(ll i=1;i<=n-1;++i) if(cmp(a[i],a[i+1])==0) swap(a[i],a[i+1]);
			for(ll i=n;i>=2;--i) if(cmp(a[i-1],a[i])==0) swap(a[i-1],a[i]);
            for(ll i=1;i<=n;++i)
            b[a[i].id]=i;
        }
        else{
            cin>>x;
            cout<<b[x]<<"\n";
        }
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
