#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll a,b,x,y;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	char c;
	while(cin>>x){
		cin>>c>>y;
		if(a==0&&b==0){
			a=x,b=y;
			continue;
		}
		ll gcd=__gcd(b,y),gcd1=y/gcd,gcd2=b/gcd;
		a=a*gcd1+x*gcd2;
		b=b*gcd1;
		ll gcd3=__gcd(a,b);
		a/=gcd3;
		b/=gcd3;
		if(a>0&&b<0) a=-a,b=-b;
	}
	if(a%b!=0) cout<<a<<"/"<<b<<"\n";
	else cout<<a/b;
    return 0;
}
