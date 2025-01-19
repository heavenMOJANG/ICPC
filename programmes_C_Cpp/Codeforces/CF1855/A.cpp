#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n,res,a[100010];
void solve(){
	cin>>n;
    res=0;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==i) res++;
	}
	if(res%2==0) cout<<res/2<<"\n";
	else cout<<res/2+1<<"\n";
	return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>_;
    while(_--) solve();
    return 0;
}
