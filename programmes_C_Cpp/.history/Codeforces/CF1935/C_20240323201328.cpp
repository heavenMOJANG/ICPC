#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,l;cin>>n>>l;
	array<int,2>arr[n+1];
	for(int i=1;i<=n;++i) cin>>arr[i][1]>>arr[i][0];
	sort(arr+1,arr+1+n);
	int ans=0;
	for(int i=1;i<=n;++i){
		int sum=0;
		multiset<int>s;
		for(int j=i;j<=n;++j){
			s.insert(arr[j][1]);
			sum+=arr[j][1];
			while(s.size()>0&&sum+arr[j][0]-arr[i][0]>l) {
				sum-=*(--s.end());
				s.erase(--s.end());
			}
			ans = max(ans,(int)s.size());
		}
	}
	cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
