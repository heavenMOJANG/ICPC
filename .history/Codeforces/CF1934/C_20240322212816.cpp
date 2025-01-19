#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>m;
    auto query=[&](int x,int y){
	    cout<< "? "<<x<<" "<<y<<endl;
	    int res;cin>>res;
	    return res;
    };
    int u1=query(1,1),u2=query(1,m),u3=query(n,1); 
	if((u1+u3+3-n)>0&&(u1+u3+3-n)%2==0){
		int y1=(u1+u3+3-n)/2,x1=u1-y1+2;
		if(x1>=1&&x1<=n&&y1>=1&&y1<=m){
			int q=query(x1, y1);
			if(q==0){
				cout<<"! "<<x1<<" "<<y1<<endl;
				return;
			}
		}
	}
	int x1=(u1+u2+3-m)/2,y1=u1+2-x1;
	cout<<"! "<<x1<<" "<<y1<<endl;
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
