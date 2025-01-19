#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n,a[30],b[30];
void solve(){
    cin>>n;
    ll flag=0,maxn=-inf,minn=inf,maxp=0,minp=0,cntp=0,cntm=0,resp=0,resm=0;;
    vector<pair<ll,ll>>vp,vm;
    for(ll i=0;i<n;++i){
		cin>>a[i],b[i]=a[i];
		if(a[i]>0){
			cntp++;
			if(maxn<a[i]) maxn=a[i],maxp=i;	
		}
		if(a[i]<0){
			cntm++;
			if(minn>a[i]) minn=a[i],minp=i;
		}
	}
    for(ll i=0;i<n-1;++i) if(a[i]>a[i+1]){flag=1;break;}
    if(n==1||flag==0){cout<<"0\n";return;}
    if(!cntp){
		cout<<n-1<<"\n";
		for(int i=n;i>1;--i) cout<<i-1<<" "<<i<<"\n";
		return; 
	}
    if(!cntm){
		cout<<n-1<<"\n";
		for(ll i=1;i<n;++i) cout<<i+1<<" "<<i<<"\n";
		return;
	}
	while(a[maxp]<abs(minn)){
		vp.push_back({maxp+1,maxp+1});
		a[maxp]+=a[maxp];
		resp++;
	}
	while(abs(b[minp])<maxn){
		vm.push_back({minp+1,minp+1});
		b[minp]+=b[minp];
		resm++;
	}
	for(ll i=0;i<n;++i){
		if(a[i]<0){
			resp++;
			a[i]+=a[maxp];
			vp.push_back({i+1,maxp+1});
		}
		if(b[i]>0){
			resm++;
			b[i]+=b[minp];
			vm.push_back({i+1,minp+1});
		}
	}
	for(int i=1;i<n;i++){
		if(a[i]<a[i-1]){
			vp.push_back({i+1,i});
			a[i]+=a[i-1];
			resp++;
		}
	}
	for(ll i=n-2;i>=0;--i){
		if(b[i]>b[i+1]){
			vm.push_back({i+1,i+2});
			b[i]+=b[i+1];
			resm++;
		}
	}
	if(resp<resm){
		cout<<resp<<"\n";
		for(auto it:vp)
		cout<<it.first<<" "<<it.second<<"\n";
	}
	else{
		cout<<resm<<"\n";
		for(auto it:vm)
		cout<<it.first<<" "<<it.second<<"\n";
	}
	return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>_;
    while(_--) solve();
    return 0;
}
