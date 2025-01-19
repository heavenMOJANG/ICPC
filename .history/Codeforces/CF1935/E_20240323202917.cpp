#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int highbit(int x) {
	if(x==0) return -1;
	return 31-__builtin_clz(x);
}
void solve(){
    int n;cin>>n;
	vector<int>a(n+1),v1[31],v2[31];
	for(int i=1,x,y;i<=n;++i){
		cin>>x>>y;
		while(x>0&&highbit(x)==highbit(y)){
			int t=highbit(x);
			v1[t].push_back(i);
			x-=(1<<t);y-=(1<<t);
		if(y>0) v2[highbit(y)].push_back(i);
		a[i]=y;
	}
	int q;cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		int ans=0;
		for(int i=0;i<=30;++i)
			if(auto it=lower_bound(v1[i].begin(),v1[i].end(),l);it!=v1[i].end()&&*it<=r) ans|=(1<<i);
		priority_queue<int>pq;
		for(int i=30;i>=0;--i){
			int num=0;
			auto it=lower_bound(v2[i].begin(),v2[i].end(),l);
			if(it!=v2[i].end()&&*it<=r){
				num++;
				it++;
				if(it!=v2[i].end()&&*it<=r) num++;
			}
			if(num==0) continue;
			if(num>=2||(num==1&&(ans>>i&1))) ans=(ans|(1<<i)|((1<<i)-1));
            else{
				ans|=(1<<i);
				int idx=*lower_bound(v2[i].begin(),v2[i].end(),l);
				pq.push(a[idx]-(1<<i));
			}
		}
		while(!pq.empty()){
			auto t=pq.top();pq.pop();
			if(t==0) continue;
			int high=highbit(t);
			if(ans>>high&1) ans|=(1<<high)-1;
            else{
				ans|=(1<<high);
				pq.push(t-(1<<high));
			}
		}
		cout<<ans<<" ";
	} 
	cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
