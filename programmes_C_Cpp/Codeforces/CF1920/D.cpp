#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=1e18;
void solve(){
    int n,q;cin>>n>>q;
    vector<int>a(n+1,0),opt(n+1,0),num(n+1,0);
    for(int i=1,op,t;i<=n;++i){
		cin>>op>>t;
		if(op==1){
			a[i]=a[i-1]+1;
			num[i]=t;
			opt[i]=1;
		}
		else{
			if((inf+t)/(t+1)<a[i-1])a[i]=inf+1;
			else a[i]=a[i-1]*(t+1);
			num[i]=t+1;
			opt[i]=2;
		}
	}
    auto query=[&](int x){
	    for(int i=lower_bound(a.begin()+1,a.begin()+n+1,x)-a.begin();i>=1;i=lower_bound(a.begin()+1,a.begin()+i+1,x)-a.begin()){
		    if(opt[i]==1) return num[i];
		    x=((x-1)%a[i-1])+1;
	    }
    };
    for(int i=1,x;i<=q;++i) cin>>x,cout<<query(x)<<" ";
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
