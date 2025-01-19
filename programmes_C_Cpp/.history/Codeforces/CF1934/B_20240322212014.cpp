#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    int ans=1e9;
	for(int i1=0;i1<=2;++i1)
        for(int i3=0;i3<=1;++i3) 
		    for(int i6=0;i6<=2;++i6)
                for(int i10=0;i10<=2;++i10){
			        int tot=i1+i3*3+i6*6+i10*10;
			        if(tot<=n&&(n-tot)%15==0) 
				    ans = min(ans,(n-tot)/15+i1+i3+i6+i10);
	            }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
