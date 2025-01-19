#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int x,y;cin>>x>>y;
	if((x^y)<x){cout<<"1\n"<<x<<" "<<y<<'\n';return;}	
 	bitset<64>b1(x),b2(y);
	int cnt=0;
	for(int i=63;i>=0;--i){
		if(b1[i]==1&&b2[i]==0) cnt++;
		if(b1[i]==0&&b2[i]==1){
			if(cnt<=1){cout<<-1<<'\n';return;}
		}
	}
	int high=0;
	for(int i=63;i>=0;--i)
		if(b1[i]!=b2[i]){high=i;break;}
	cout<<"2\n";
	int t=(x^y)^(1ll<<high);
	cout<<x<<" "<<(x^t)<<" "<<y<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
