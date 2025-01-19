#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,w,h[610],p;
void solve(){
    cin>>n>>w;
    for(ll i=1,x;i<=n;++i){
		cin>>x;
		h[x]++;
		p=i*w/100;
		if(p==0) p++;
		for(ll j=600;j>=0;--j){
			if(h[j]>=1) p-=h[j];
			if(p<=0){cout<<j<<" ";break;}
		}
	}
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}