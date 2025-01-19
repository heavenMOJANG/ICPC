#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll a,b,c;
ll check(double x){
	double res=a;
	for(ll i=1;i<=c;++i) res+=res*x,res-=b;
    return res<=0;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b>>c;
    double l=0,r=500;
	for(ll i=1;i<=100;++i){
		double mid=(l+r)/2;
		if(check(mid/100)) l=mid;
		else r=mid;
	}
    cout<<fixed<<setprecision(1)<<l;
    return 0;
}