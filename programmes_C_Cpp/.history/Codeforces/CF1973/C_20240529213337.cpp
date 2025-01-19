#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;++i) cin>>a[i];
	vector<pii>b,c;
	for(int i=1;i<=n;++i)
		if (i%2== 0&&i!=n) b.emplace_back({a[i],i});
		else c.push_back({a[i],i});
	sort(b.begin(),b.end());
	int cur = n;
	vector<int> res(n + 1);
	for (int i = 0; i < b.size(); i ++ ) {
		res[b[i].second] = cur --;
	}
	sort(c.begin(), c.end());
	for (int i = 0; i < c.size(); i ++ ) {
		res[c[i].second] = cur --;
	}
	vector<int> temp(n + 1);
	for (int i = 1; i <= n; i ++ ) {
		temp[i] = res[i] + a[i];
	}
	int cnt = 0;
	for (int i = 2; i < n; i ++ ) {
		if (temp[i] > temp[i - 1] && temp[i] > temp[i + 1]) cnt += 1;
	}
	if (cnt == (n - 2) / 2) {
		for (int i = 1; i <= n; i ++ ) cout << res[i] << ' ';
		cout << endl;
		return;
	}
	b.clear(), c.clear();
	for (int i=1;i<=n;++i) 
		if (i&1&&i!=1) {
			b.emplace_back({a[i], i});
		}else {
			c.push_back({a[i], i});
		}
	sort(b.begin(), b.end());
	cur=n;
	res.clear();
	for(int i=0;i<b.size();++i) res[b[i].second]=cur--;
	sort(c.begin(),c.end());
	for(int i=0;i<c.size();++i) res[c[i].second]=cur--;
	for(int i=1;i<=n;++i) cout<<res[i]<<" ";
	cout<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}