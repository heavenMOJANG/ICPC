#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=998244353;
void solve(){
    int n,q;cin>>n>>q;
	string s;cin>>s;
    s=" "+s;
    int ans=1;
    for(int i=2;i<n;++i) if(s[i]=='?') ans=ans*(i-1)%mod;
	auto check=[&]()->void
	{
		if(s[1]=='?') cout<<"0\n";
    	else cout<<ans<<"\n";
	};
    check();
	auto qpow=[&](int a,int x)->int
	{
		int res=1;
		while(x){
			if(x&1) res=res*a%mod;
			a=a*a%mod;
			x>>=1;
		}
		return res;
	};
    while(q--){
        int p;char ch;
        cin>>p>>ch;
        if(p!=1){
            if(s[p]=='?') ans=ans*qpow(p-1,mod-2)%mod;
            if(ch=='?') ans=ans*(p-1)%mod;
        }
        s[p]=ch;
        check();
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
