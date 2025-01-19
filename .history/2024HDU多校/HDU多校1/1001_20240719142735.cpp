#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int unsigned long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod1=998244353;
constexpr int mod2=19260817;
constexpr int N=1e6+10,p=131;
int a1[N],a2[N],hs1[N],hs2[N],hs3[N],hs4[N];
void init(){
	a1[0]=a2[0]=1;
	for(int i=1;i<N;++i){
		a1[i]=a1[i-1]*p%mod1;
		a2[i]=a2[i-1]*p%mod2;
	}
}
void hashstr1(string&str){
	int n=str.size();
	for(int i=1;i<=n;++i){
		hs1[i]=(hs1[i-1]*p%mod1+str[i-1])%mod1;
		hs2[i]=(hs2[i-1]*p%mod2+str[i-1])%mod2;
	}
}
void hashstr2(string&str){
	int n=str.size();
	for(int i=1;i<=n;++i){
		hs3[i]=(hs3[i-1]*p%mod1+str[i-1])%mod1;
		hs4[i]=(hs4[i-1]*p%mod2+str[i-1])%mod2;
	}
}
int getHash1(int l,int r){
	return (hs1[r]-hs1[l-1]*a1[r-l+1]%mod1+mod1)%mod1;
}
int getHash2(int l,int r){
	return (hs2[r]-hs2[l-1]*a2[r-l+1]%mod2+mod2)%mod2;
}
int getHash3(int l,int r){
	return (hs3[r]-hs3[l-1]*a1[r-l+1]%mod1+mod1)%mod1;
}
int getHash4(int l,int r){
	return (hs4[r]-hs4[l-1]*a2[r-l+1]%mod2+mod2)%mod2;
}
void solve(){
    string a,b;cin>>a>>b;
    int n=a.size(),ans=0;
    a=a+a;
    hashstr1(a);
    hashstr2(b);
    map<pii,int>mp;
    for(int i=0;i+n-1<a.size();++i) mp[{getHash1(i+1,i+n),getHash2(i+1,i+n)}]=1;
    for(int i=0;i+n-1<b.size();++i)
        if(mp[{getHash3(i+1,i+n),getHash4(i,i+n)}]==1) ans++;
    cout<<ans<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    init();
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}