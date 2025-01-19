#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n;
void solve(ll x){
	ll p=0,k=x,u=0,h[50];
	while(k){
		if(k&1) h[++u]=p;
		k>>=1;
		p++;
	}
	while(u)
		if(h[u]<3){
			if(h[u]==1&&u-1!=0)  cout<<"2+";
			else if(h[u]==1) cout<<"2";
			if((h[u]==0||h[u]==2)&&(u-1!=0))  cout<<"2("<<h[u]<<")+";
			else if(h[u]==0||h[u]==2) cout<<"2("<<h[u]<<")";	
			u--;
		}
		else{
			cout<<"2(";
			solve(h[u--]);
            cout<<(u==0?")":")+");
		}
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    solve(n);
    return 0;
}