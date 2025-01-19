#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
	if(bitset<64>(n).count()%2){
		cout<<"second"<<endl;
		int p1,p2;cin>>p1>>p2;
		if(p1==0&&p2==0){return;}
		if(bitset<64>(p1).count()%2==0) n=p1;
        else n=p2;
	}
    else cout<<"first"<<endl;
	while(1){
		bitset<64>b(n);
		for(int i=63;i>=0;--i){
			if(b[i]==0) continue;
			cout<<(1ll<<i)<<" "<<(n^(1ll<<i))<<endl;
			break;
		}
		int p1,p2;cin>>p1>>p2;
		if(p1==0&&p2==0) return;
		if(bitset<64>(p1).count()%2==0) n=p1;
        else n=p2;
	}
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
