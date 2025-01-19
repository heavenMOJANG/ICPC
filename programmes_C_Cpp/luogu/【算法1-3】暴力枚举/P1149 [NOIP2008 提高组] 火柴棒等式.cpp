#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,a[10]={6,2,5,5,4,5,6,3,7,6},sum; 
ll cal(ll x){
	ll res=0;
	do{
		res+=a[x%10];
		x/=10;
	}while(x);
	return res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    n-=4;
    for(ll i=0;i<1000;++i)
		for(ll j=0;j<1000;++j) if(cal(i)+cal(j)+cal(i+j)==n) sum++;
    cout<<sum;
    return 0;
}