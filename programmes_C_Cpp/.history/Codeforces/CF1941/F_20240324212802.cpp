#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m,k;cin>>n>>m>>k;
	vector<int>a(n+1),b(m+1),c(k+1);
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=m;++i) cin>>b[i];
	for(int i=1;i<=k;++i) cin>>c[i];
	sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
	int pos,mx=LLONG_MIN,num=0,mx_2=LLONG_MIN;
	for(int i=2;i<=n;++i)
		if(a[i]-a[i-1]>mx){
			mx_2=mx;
			mx=a[i]-a[i-1];
            pos=i;
            num=1;
		}
		else if(a[i]-a[i-1]==mx) num++,mx_2=mx; 
		else if(a[i]-a[i-1]>mx_2) mx_2=a[i]-a[i-1];
	if(num>1){cout<<mx<<"\n";return;}
	auto check=[&](int mid){
		for(int i=1,j=k;i<=m&&j>=1;++i){
			while(j>=1&&b[i]+c[j]>a[pos]) j--;
			while(j>=1&&b[i]+c[j]>(a[pos-1]+a[pos])/2){
				int res=b[i]+c[j];
				int mn=max(abs(res-a[pos-1]),abs(res-a[pos]));
				if(mn<=mid) return 1;
				j--;
			}
			if(j&&b[i]+c[j]>=a[pos-1]&&b[i]+c[j]<=a[pos]){
				int res=b[i]+c[j];
				int mn=max(abs(res-a[pos-1]),abs(res-a[pos]));
				if(mn<=mid) return 1;
			}
		}
		return 0;
	};
	int l=0,r=mx;
	while(l+1!=r){
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	r=max(r,mx_2);
	cout<<r<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
