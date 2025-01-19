#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ull n,a,b;
__int128 c[60][60],res;
inline void writeln(__int128 n){
    if(n<0){putchar('-');n*=-1;}
    if(n>9) writeln(n/10);
    putchar(n%10+'0');
}
void init(){
	ll num=n+max(a,b); 
	for(ll i=0;i<=num;++i) c[i][0]=1,c[i][i]=1;
	for(ll i=1;i<=num;++i)
		for(ll j=1;j<=i;++j) c[i][j]=c[i-1][j-1]+c[i-1][j];
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>a>>b;
	init();
	for(ll i=0;i<=a;++i)
		for(ll j=0;j<=b;++j) res+=c[n+i-1][n-1]*c[n+j-1][n-1];
	writeln(res);
    return 0;
}
