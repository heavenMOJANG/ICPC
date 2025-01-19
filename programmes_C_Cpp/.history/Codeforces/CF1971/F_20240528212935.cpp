#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int d;cin>>d;
    int res=0;
    for(int i=1;i<=d;++i){
			int tl=0;
			int l=0,r=d;
			while(l<r) {
				int mid=l+r+1>>1;
				if(mid*mid+i*i<d*d) l=mid;
				else r=mid-1; 
			}
			tl=l;
			l=0,r=d;
			while(l<r){
				int mid=l+r+1>>1;
				if(mid*mid+i*i<(d+1)*(d+1)) l=mid;
				else r=mid-1;
			}
			res+=r-tl;
		}
		cout<<4*(res+1)<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}