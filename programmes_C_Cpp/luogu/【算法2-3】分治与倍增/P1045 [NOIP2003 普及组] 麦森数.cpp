#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll p,ans[1010],temp[1010],c[1010];
void Multiply_1(){
	memset(c,0,sizeof(c));
	for(ll i=1;i<=500;++i)
		for(ll j=1;j<=500;++j) c[i+j-1]+=ans[i]*temp[j];
	for (ll i=1;i<=500;++i) c[i+1]+=c[i]/10,c[i]%=10;
	memcpy(ans,c,sizeof(c));
}
void Multiply_2(){
	memset(c,0,sizeof(c));
	for(ll i=1;i<=500;++i)
		for(ll j=1;j<=500;++j) c[i+j-1]+=temp[i]*temp[j];
	for(ll i=1;i<=500;++i) c[i+1]+=c[i]/10,c[i]%=10;
	memcpy(temp,c,sizeof(c));
}
void Quick_Power(ll p){
	while(p){
		if(p&1) Multiply_1();
		Multiply_2();
		p>>=1;
	}
	return;
}
int main(int argc,const char*arv[]){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>p;
	cout<<(ll)floor(log(2)/log(10)*p+1)<<"\n";
	ans[1]=1,temp[1]=2;
	Quick_Power(p);
	ans[1]--;
	for(ll i=500;i>=1;--i){
		cout<<ans[i];
		if(i%50==1) cout<<"\n";
	}
    return 0;
}