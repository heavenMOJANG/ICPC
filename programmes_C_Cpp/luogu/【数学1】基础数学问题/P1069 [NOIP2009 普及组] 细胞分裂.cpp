#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,t,m1,m2,num,p[30],a[30],s,ans=-1;
void split(ll x){
	num=0;
	for(ll i=2;i<=sqrt(x);++i){
		if(x%i!=0) continue;
		p[++num]=i;
		a[num]=0;
		while(x%i==0) a[num]++,x/=i;
		a[num]*=m2;
	}
	if(x>1) p[++num]=x,a[num]=m2;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m1>>m2;
	split(m1);
	for(ll i=1;i<=n;++i){
		ll t=0,flag=1;
		cin>>s;
		for(ll j=1;j<=num;++j){
			if(s%p[j]){flag=0;break;}
			ll x=0;
			while(s%p[j]==0){
				x++;
				s/=p[j];
			}
			t=max(t,(ll)ceil((a[j]-1)/x)+1);
		}
		if(flag) if(ans==-1||t<ans) ans=t;
	}
	cout<<ans;
    return 0;
}
