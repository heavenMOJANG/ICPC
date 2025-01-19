#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,len=1,sum[100010]={0,1};
struct Node{ll l,r;}m[1000010];
ll cmp(Node a,Node b){return a.l*a.r<b.l*b.r;}
void multiply(ll x){
	for(ll i=1;i<=len;++i) sum[i]*=x; 
	for(ll i=1;i<=len;++i) sum[i+1]+=sum[i]/10,sum[i]%=10;
	len++;
	while(sum[len]/10) sum[len+1]=sum[len]/10,sum[len++]%=10;
	if(sum[len]==0) len--;
}
void divide(){
	for(ll i=len;i>=1;--i) sum[i-1]+=(sum[i]%m[n].r*10),sum[i]/=m[n].r;
	while(!sum[len]) len--;
	if(len==0) cout<<"1\n"; 
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>m[0].l>>m[0].r;
	for(ll i=1;i<=n;++i) cin>>m[i].l>>m[i].r;
	sort(m+1,m+1+n,cmp);
	for(ll i=0;i<n;++i) multiply(m[i].l); 
	divide();
	for(ll i=len;i>=1;--i) cout<<sum[i];
    return 0;
}