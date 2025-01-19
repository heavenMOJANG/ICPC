#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Node{
    ll l,r;
    bool operator<(const Node&x)const{return l<x.l;}
}t[100010];
ll n,res,R;
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>t[i].l>>t[i].r;
    sort(t+1,t+1+n);
    res=t[1].r-t[1].l;
    R=t[1].r;
    for(ll i=2;i<=n;++i){
		if(t[i].l<R){
			if(t[i].r<=R) continue;
			else res+=t[i].r-R,R=t[i].r;
		}
		else{
			res+=t[i].r-t[i].l;
			R=t[i].r;
		}
	}
    cout<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}