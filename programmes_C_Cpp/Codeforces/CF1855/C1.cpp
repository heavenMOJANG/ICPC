#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n,a[30];
void solve(){
    cin>>n;
	ll cnt=0,maxn=0,id=0;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>0){
			cnt++;
			if(maxn<cnt) maxn=cnt,id=i;
		}
	}
	if(cnt==0){
		cout<<n-1<<"\n";
		for(ll i=n;i>1;--i) cout<<i-1<<" "<<i<<"\n";
	}
	else{
		cout<<2*n+4<<"\n";
		for(ll i=1;i<=5;++i) cout<<id<<" "<<id<<"\n";
		for(ll i=1;i<=n;i++) cout<<i<<" "<<id<<"\n";
		for(ll i=1;i<n;i++) cout<<i+1<<" "<<i<<"\n";
	}
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>_;
    while(_--) solve();
    return 0;
}
